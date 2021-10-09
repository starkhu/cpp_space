## __getattr__的作用：
  在类对象进行属性查找（__dict__）失败时，就会调用类的__getattr__函数，如果还没有定义这个函数，就会跑出AttributeError异常。

```python
#demo1
class Tree:
    def __init__(self):
        self.branch = "branch1"
    def __getattr__(self, name):
        print("Tree class, __getattr__ function")

tree = Tree()
tree.branch
tree.leaves
打印结果：
Tree class, __getattr__ function
```
如demo1打印结果所示：运行tree对象调用branch变量时，直接找到就没有__getattr__函数了，调用tree.leaves没有找到，才开始到__getattr__函数中寻找。

## 利用__getattr__函数的特色，可以对类的实现特殊的功能
### 场景1：惰性初始化
如果想在构造函数之外给类对象添加一个新的成员，可以通过这个函数
```python
#demo2
class Tree:
    def __init__(self):
        self.branch = "branch1"
    def __getattr__(self, name):
        if name not in self.__dict__:
            self.__dict__[name] = name
        return self.__dict__[name]

tree = Tree()
print(tree.branch)
print(tree.leaves)

打印结果：
branch1
leaves
```

### 场景2：如果类成员中有一个dict，可以像访问类成员一样访问该dict中的成员
```python
class Tree:
    def __init__(self):
        self.branch = "branch1"
        self.branchs = {"branch1": 1, "branch2": 2}
    def __getattr__(self, name):
        if name not in self.__dict__:
            if name in self.branchs.keys():
                return self.branchs[name]
            self.__dict__[name] = name
        return self.__dict__[name]

tree = Tree()
print(tree.branch)
print(tree.leaves)
print(tree.branch1)

打印结果：
branch1
leaves
1
```

### 场景3：类A获取类B的所有方法，一种"组合替代继承"的实现。
```python
class Tree:
    def __init__(self):
        self.branch = "branch1"
        self.branchs = {"branch1": 1, "branch2": 2}
    def root(self):
        print("Tree root")
    def leaf(self):
        print("Tree leaf")
    def __getattr__(self, name):
        if name not in self.__dict__:
            if name in self.branchs.keys():
                return self.branchs[name]
            self.__dict__[name] = name
        return self.__dict__[name]

class FakeTree:
    def __init__(self):
        self.tree = Tree()

    def root(self):
        print("FakeTree root")

    def __getattr__(self, name):
        return getattr(self.tree, name)

tree = FakeTree()
print(tree.branch)
print(tree.branch1)
tree.root()
tree.leaf()

打印结果：
branch1
1
FakeTree root
Tree leaf
```
