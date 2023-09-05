make `git rev-list --count HEAD` easy to type by just calling it `qwd q`.

## Safe commands

type | to do
---  | ---
`qwd q` | `git rev-list --count HEAD`
`qwd qw` | `git branch`
`qwd w` | `git log -3`
`qwd wd` | `git diff --cached`

## Destructive commands

type | to do 
---  | ---
`qwd qwd` | I made some changes, but I don't remember what I did. Create a commit for me.

## Installing

via PyPI, run `pip install qwd`.
