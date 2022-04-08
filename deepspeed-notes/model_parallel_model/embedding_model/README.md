本文件用来介绍模型并行策略是如何优化 Embedding 模块的。主要分为两个阶段介绍：
- 1. 介绍正常模式下（mp_size=1）的 Embedding 模块。
- 2. 介绍模型并行模式下（mp_size>1）的 Embedding 模块。

## 故事会
A翻译社接到一个翻译文稿的任务，该文稿有10个章节，如果让社里的张三翻译的话， 需要10天才能翻译完成。
但客户需要的比较急，需要2天就要拿到翻译稿，社长苦苦思索一分钟，提出了一个解决之道，
召集社里的张三，李四，王五，赵六，孙七， 每人翻译两章节，最后合起来就是一部完整的翻译稿。


## 名词解释
batch_size：单词输入的句子数
seq_len：句子中单词的个数
hidden_size：用多长的数组表征一个单词
vocab_size：词表中单词（tokens）的个数


## 正常模式下的 Embedding 模块
NLP网络的输入通常是句子，假设单次输入只有一个句子时（batch_size=1），输入如下例：
```
Large deep learning models offer significant accuracy gain.
```
通过查词表获取句子中单词在词表中的索引。 此时输入转换成单词索引组成的向量，其 shape 为[batch_size, seq_len]

```
[[20, 31, 42, 33, 54, 66, 71, 82]]
```

NLP网络第一个阶段通常是将输入转换成词向量，即通过查表获取单词对应的向量。此时输入 Tensor 的 shape 是[batch_size, seq_len, hidden_size]
```
#input 是输入， vocab_weight 是 shape 为[vocab_size, hidden_size] 的 Parameter。
embedded_output = F.embedding(input, vocab_weight)
```

## 模型并行模式下的 Embedding 模块
### 优化方向
通常词表需要囊括训练集中绝大部分的单词， 因此单词个数很大。当表征单词的数组长度越长时，蕴含的信息越多，因此数组长度也是越大越好。
因此假设 vocab_size 为50000， hidden_size 为 1024, 因此表征单词向量的参数 vocab_weight 大小约为 195MiB 。
而大规模训练中内存是很珍贵的资源，因此最好节约使用。

因此模型并行策略希望可以将 vocab_weight  分散到各个 device上，这样每张卡上仅需要占用 （195/mp_size）MiB。
这样实现的另一个好处是反向更新梯度阶段和更新权值阶段，vocab_weight 对应的梯度和权值大小也仅为正常模式下的 1/mp_size，可减低通信开销，加快训练速度。

### 实现方法
将 vocab_weight 按第 0 维度切分成 mp_size 份，每个device上保存一份， 这样每个 device 上 vocab_weight 的 shape 为 [vocab_size/mp_size, hidden_size]。
模型并行时，每张卡上的输入是一样的， 每张卡仅查找索引范围的单词向量，不在索引范围内的单词index对应的向量置零。
然后通过 all_reduce 通信获取完整的输入。

