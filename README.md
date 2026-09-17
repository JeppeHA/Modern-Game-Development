# Modern-Game-Development

## Locking a file 

1. git pull --rebase
  always before you open the editor. Locking a stale file still costs you the merge.
2. git lfs locks
  See what is already held, and by whom, before you plan your day.
3. git lfs lock Content/Maps/MyLevel.umap
  Claim the file. Others now see it as locked and keep it read-only.
4. commit → push → git lfs unlock <path>
  Release as soon as you are done. Small, frequent pushes keep locks short
