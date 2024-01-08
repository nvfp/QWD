Make `git rev-list --count HEAD` easy to type by just calling it `qwd q`.

## Safe commands

type | to do
---  | ---
`qwd q` | `git rev-list --count HEAD`
`qwd qw` | `git branch`
`qwd w` | `git log -3`
`qwd wd` | `git diff --cached`
`qwd ww` | `git status`
`qwd wdwd` | `git diff --cached --stat --compact-summary`
`qwd qdq` | `git status` + `git branch`


## Destructive commands

Each destructive command prompts confirmation before execution.

- ### `qwd qwd`:
    - ⚙️ flow: `git status` → `git add .` → `git commit -m "<auto generated>"`
    - 🌟 help: Make a commit with an auto-generated commit message (optionally with a header commit, if given).
    - ❤️ examples: `qwd qwd` | `qwd qwd this is the header commit`
- ### `qwd d`:
    - ⚙️ flow: `git status` → `git branch` → `git checkout -b up`
    - 🌟 help: Prepare to make changes by creating a new branch named 'up'.
- ### `qwd dd`:
    - ⚙️ flow: `git push origin up`
    - 🌟 help: Done making changes, now pushing the 'up' branch to create a PR.
- ### `qwd dwd`:
    - ⚙️ flow: `git status` → `git branch` → `git checkout main` → `git pull` → `git branch -D up` → `git branch` → `git status`
    - 🌟 help: PR merged, back to the default branch, deleting the 'up' branch.
- ### `qwd wdw`:
    - ⚙️ flow: `git status` → `git add .` → `git commit -m <given from the user input>`
    - 🌟 help: Easily type the commit message without needing double quotes (warning: don't use symbols that can be executed by the shell like `>`).
    - ❤️ examples: `qwd wdw this is the commit message`
- ### `qwd `:
    - ⚙️ flow: `git init` → `echo init > README.md` → `git add .` → `git commit -m "init commit"`
    - 🌟 help: init fresh empty repo
- ### `qwd `:
    - ⚙️ flow: `git add .` → `git status`
    - 🌟 help: to exit from terminal (designed for Windows, idk if it's work for macOS/Linux)
- ### `qwd `:
    - ⚙️ flow: `exit`
    - 🌟 help: to exit from terminal (designed for Windows, idk if it's work for macOS/Linux)
- ### `qwd `:
    - ⚙️ flow: `git push`
    - 🌟 help: to exit from terminal (designed for Windows, idk if it's work for macOS/Linux)
- ### `qwd `:
    - ⚙️ flow: `git push --tags`
    - 🌟 help: to exit from terminal (designed for Windows, idk if it's work for macOS/Linux)


## Installing

1. Download the stable version from the release tab.
1. Inside the root project folder, run `make` to build the program.
1. Done, You are great!

## License

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
