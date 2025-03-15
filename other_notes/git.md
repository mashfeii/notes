# 2024-05-30 11:27

## Git and GitHub

`git` is a version control system (works with branches, commits, etc.).
_GitHub/GitLab/Bitbucket_ provide user interface, web-access and other utilities to more comfort
interaction with `git`

There are two ways to clone repository: by `http` and `ssh`. Public repository can be cloned by
anyone, but commits are disabled for non-authorized users, private can be cloned only by key/tokens
owners.

> [!IMPORTANT]
> It is better to clone repository by `ssh`, since GitHub removed authentication by
> login/password.

For branch switching `git checkout -b main_of_branch`, where `-b` means create new branch if it is
not existed

If something went wrong with commit (forget to include some files), one can restore the last commit
with `git restore --soft HEAD~1`, where `--soft` remove commit from git, but do not remove changed
file, `HEAD~1` responds to branch and amount of commits

To take all the commits from another branch, one can use `git merge name_of_other_branch`, git will
try to merge files by itself, but something one needs to merge with his hands. After it is possible
to see changes by `git merge --continue`

`pull request` is a *GitHub* feature, it can determine, that some of your
branches is ahead with commits than main one, and may offer to create `pull
request`


`git stash` can be used as temporary storage for some changes in project, when one does not want to
commit, but save his work somewhere implicitly. `git stash apply` used for taking changes out
