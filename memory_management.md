Symbolic address - used in source program (vars, etc)
Relative - Mem address relative to the process
Physical - actual addresses in RAM

Memory placement stratagies
- **Fetch Strategies**
    - On demand
    - Anticipatory

- **Placement Strategies**
    - **First Fit:** If it fits, it ships
    - **Best Fit:** Tightest fit that leaves the least amount of wasted memory
    - **Worst Fit:** Finds largest amount of free memory slot and placing it there. Hopefully big enough to place future programs in memory

**Memory Partitioning**
- Contiuous
    -   issues: internal fragmentation, fixed size holes
- Dynamic
    -   Variable sized partitions
        - Created when sufficient memory is available
        - \# of partitions is variable
        - Blocks of available memory is called holes
    - Still have fragmentation, but is external (doesn't happen w/in process memory)
- Non-contiguous
    - Helps remove frag
    - Paging
    Segmentation