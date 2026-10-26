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

## Comments in unreal

To make a comment in a blue print select all the nodes you want included in the comment
and the just pres **C** this creates a comment box around them.

### Organization

For better organizing our code use this color palette for the comments so we can quickly identiy what propurse of the code.

| Purpose                | Color  | Hex       | Usage                                            |
| ---------------------- | ------ | --------- | ------------------------------------------------ |
| Input / Events         | Blue   | `#3B82F6` | Input actions, event entry points                |
| Core Logic / Gameplay  | Green  | `#22C55E` | Main gameplay rules and systems                  |
| UI / HUD               | Purple | `#A855F7` | Widgets, menus, HUD updates                      |
| Movement / Physics     | Orange | `#F97316` | Character movement, forces, collisions           |
| Audio / VFX            | Teal   | `#14B8A6` | Sounds, particles, Niagara effects               |
| Animation              | Pink   | `#EC4899` | Montages, anim state logic                       |
| Debug / Temporary      | Yellow | `#EAB308` | Print strings, test code, remove before shipping |
| TODO / Needs Fixing    | Red    | `#EF4444` | Broken or unfinished logic                       |
| Setup / Initialization | Grey   | `#9CA3AF` | BeginPlay setup, variable init                   |
| Cleanup / Destroy      | Brown  | `#A16207` | Destroy actor, unbinding, teardown               |
