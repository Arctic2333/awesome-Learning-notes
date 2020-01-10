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

