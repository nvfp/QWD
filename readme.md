Make `git rev-list --count HEAD` easy to type by just calling it `qwd q`.

## Safe commands

type | to do
---  | ---
`qwd q` | `git rev-list --count HEAD`
`qwd qw` | `git branch`
`qwd w` | `git log -3`
`qwd wd` | `git diff --cached`
`qwd ww` | `git status`
<!-- `qwd wdwd` | `git add .` → `git diff --cached --stat --compact-summary` -->
`qwd wdwd` | `git diff --cached --stat --compact-summary`

## Destructive commands (coming soon)

Each destructive command prompts confirmation before execution.

type | to do | translation
---  | --- | ---
`qwd qwd` | `git status` → `git add .` → `git commit -m "<auto generated>"` | I made some changes, but I don't remember what I did. Create a commit for me.
<!-- `qwd d` | `git status` → `git pull` → `git status` → `git branch` → `git checkout -b up` | making changes -->
`qwd d` | `git status` → `git branch` → `git checkout -b up` | making changes by making new branch named "up"
`qwd dd` | `git push origin up` | push and PR

## Installing

<!-- via PyPI, run `pip install qwd`. -->
```sh
# gcc main.c -o qwd
gcc src/main.c src/utils.c -o qwd
```
