Symbolic address - used in source program (vars, etc)
Relative - Mem address relative to the process
Physical - actual addresses in RAM

### Memory placement stratagies
- **Fetch Strategies**
    - On demand
    - Anticipatory

- **Placement Strategies**
    - **First Fit:** If it fits, it ships
    - **Best Fit:** Tightest fit that leaves the least amount of wasted memory
    - **Worst Fit:** Finds largest amount of free memory slot and placing it there. Hopefully big enough to place future programs in memory

### Memory Partitioning
- Contiuous
    -   Almost impossible to acheive since programs enter and leave memory all the time
    -   issues: internal fragmentation, fixed size holes
- Dynamic
    -   Variable sized partitions
        - Created when sufficient memory is available
        - \# of partitions is variable
        - Blocks of available memory is called holes
    - Still have fragmentation, but is external (doesn't happen w/in process memory)
- Non-contiguous
    - Helps remove frag
    ### Paging - Divides the process address space into small fixed sized blocks of logical memory called pages
        process size is measured in \# of pages
        physcal memory is divided into frames (about the same size as a page)
            page size is a power of 2
        Typically, 1 page maps to 1 frame of physical memory
        Addressing requires the page \# and an offset (\# of bytes into page)
        0000000010    011011110
        Page          Offset

        - Pros: No external frag, simple, swapping is easy, transparent to programmer
        - Cons: Internal on last page of process mem, page tables may consume more memory, can protect mem by marking whether or not a frame is valid or invalid (not much mem protection)
    ### Segmentation - Variable length modules of a program corresponding to logical units (addresses)
        Secure: You don't know where memory of a program starts or ends.
        Linux does not use it at a process level. Avoids it as much as possible.
            Kernel space and userspace data and code only.
        Segmentation faults in Linux explained
            Legacy phrase. That's it.
            Just accessing memory outside of program allocation.
        OSs can overlys segs on top of paging: a process has segments, and those segments directly map to one or more pages.
        
        Process locality and locality of reference
            Set of pages a rocess operates on are called a locality
            Temporal locality - data recently used is likely to be reused
            Spatial - data element x was, so data close to it in physical mem may be used soon.

            Eploited to avoid page faults as much as possible
            
            Address translation
                Check valid page \# and physical address
                    Else page fault (if page not in memory)
                Loading too much into pages is bad, but too little is also bad

            Page fault and performance
                Time to service page fault is important (lots of overhead)
                (0<= p <= 1.0) = 0 is no page fault, 1 is every reference is a fault.

                [Page 14 of chapter 16 slides]

    Paging algorithm
        - Assume process has stream of pages it references (per process)
        - FIFO [slide 16 of chapter 16]