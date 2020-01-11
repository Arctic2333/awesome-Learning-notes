# **Git Learned Command Daquan**

- **pwd** 用于显示当前目录

- **cd/d/GitHub/git_learn** 把操作对象切换成d盘的github版本仓库

- **git init** 把当前目录变成Git可以管理的仓库

- **git add** 把文件提交到暂存区

- **git commit** 把文件提交到仓库

- **git commit -m "xxx"** 添加改动说明

- **git status** 显示当前仓库的状态

- **git diff** 查看修改的具体内容

- **git log** 显示历史版本

- **git log --pretty=oneline** 只显示一行简略的历史版本

- **HEAD**表示当前版本 **head^**表示上一个版本 **head^^**表示上上一个版本 **head~100**表示往上100个版本

- **git reset --hard HEAD^** 回退到上一个版本

- **git reset --hard <commit id(版本号不用写全)>** 回退到指定版本

- **git reflog** 显示记录每次的命令

- **git checkout -- file** 可以丢弃工作区的修改 两种情况：一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

  一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态

- **git reset HEAD** 把暂存区的修改撤销掉（unstage），重新放回工作区

- **git rm file**删除文件 **git rm file** 与 **git add file** 一样都是先提交到**stage**然后**git commit**

- 如果已经提交到版本库了，误删可以通过命令 **git cheackout -- file** 找回，只能回到最近版本

- **git branch** 查看分支 当前分支有*****号标识

- **git branch <name>** 创建分支

- **git checkout <name>** 或 **git switch <name>** 切换分支

- **git checkout -b <name>** 或 **git switch -c <name>**  创建并切换分支

- **git merge <name>** 把某分支合并到当前分支

- **git branch -d <name>** 删除分支

- **git log --graph** 可以查看分支合并图 

- **git log --graph --pretty=online --abbrev-commit** 更简明的缩略图

- **git merge --no-ff -m "xxxxx"** 禁用fast forward模式 会产生一个**commit** 所以加-**m “  xxx ”**

- **git stash** 把当前工作现场“储藏”起来

- **git stash list** 查看“储藏”的工作现场

-  **git stash apply**恢复工作现场，但是恢复后，stash内容并不删除，你需要用**git stash drop**来删除； 

- **git stash pop** 恢复工作现场的同时把stash的内容也删除

- **git stash apply stash@{<number>}** 多次stash后恢复指定的stash

- **git stash drop stash@{<number>}** 删除指定的stash

- **git cherry-pick <commit_num>** 复制一个特定的提交到当前分支

- **git branch -D <name>** 强制删除一个没被合并的分支

- ** git remote -v** 查看远程库信息

- **git push origin branch-name** 推送本地修改到远程库某分支

- **git pull** 抓取远程的新提交

- **git checkout -b branch-name origin/branch-name** 在本地创建和远程分支对应的分支（一般会自动关联）

- **git branch --set-upstream-to branch-name origin/branch-name** 建立本地分支和远程的关联

- **git rebase** 把本地未push的分叉提交历史整理成直线 

- **git tag <tagname> <commitId>** 用于新建标签，默认是HEAD也可以指定一个commit

- **git tag -a<tagname> -m "xxxxx"** 可以指定标签信息

- **git tag** 查看所有标签

- **git show <tagname>** 查看标签信息

- **git push origin <tagname>** 推送一个本地标签

- **git push origin --tags** 可以推送全部未推送的本地标签

- **git tag -d <tagname>** 可以删除一个本地标签

- **git push origin :refs/tags/<tagname>** 可以删除一个远程标签（要先删除本地标签）

  

