git log -p file_name // 查看这个文件的历史修改记录

git reflog  // 查看所有分支的所有操作，包括已经被删除的分支

git reset HEAD file_name // 用于取消已经git add到缓存区的文件

git status -uno  // -uno 不显示未跟踪的文件

git log --name-status // 显示每次修改的文件列表，文件状态

git log --name-only // 显示每次修改的文件列表



打标签

在指定的commit-id中添加标签：git tag -a tag_label commit_id

删除标签： tig tag -d tag_label

查看标签： git log --decorate --graph

git tag可以查看打了多少标签





1.2 gitlab提交的规范流程：

(1) git checkout -b local_branch remote_target_master

(2) 经常rebase，保持本地分支跟远端最新分支同步，这样自己提交就没有冲突了。

(3) 万一，一段时间忘记更新了,使用该命令更新：git pull --rebase, 如果冲突了，解决冲突后git add，用git rebase --continue 继续完成rebase.



1.3 打补丁：

生成补丁：

git format-patch commit-id :将这次提交之后的内容一一打补丁，不包括本次提交。

git format-patch commit-id -n : 将本次及前（n-1）次提交打补丁。

打补丁：

git apply --check XXX.patch // 检查补丁是否可以正常打入

git apply XXX.patch // 打入补丁

git am XXX.patch // 打补丁

解决冲突：

git apply --reject XXX.patch // 自动合入不冲突的代码，保留冲突的部分，同时生成.rej文件

解决完冲突，删除.rej文件，执行git add 添加到暂存区

执行git am --continue 或者git am --resolved

git am --skip // 跳过此次冲突

git am --abort // 会退到打patch之前的状态



1.4 隐藏修改内容：

git stash  // 隐藏修改内容

git stash pop // 恢复之前的缓存

git stash list // 查看stash列表

git stash show // 显示做了哪些修改（最近一次）

git stash show -p stash@{num} // 显示第几次的修改

git stash drop stash@{num} // 删除第num次的修改

git stash clear // 删除所有缓存


