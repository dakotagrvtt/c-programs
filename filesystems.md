**Two basic kinds**
- Volatile: contents are lost if power is lost. MUCH faster than non-volatile.
    - Cache (on CPU)
    - RAM
- Non-volatile: contents stay if power is lost.
    -   SSD, Hard drive
    - CD/DVD/Blu-ray, Tape, Old old school magnetic tube


HDD/SSD have boot sector/block to perform initial system boot

Partitions orgranize, stor and retrieve their data in ways specified by the *file system*
    -   FAT/FAT32, NTFS, ext2/3/4, Lustre, HDFS, virtual, etc

I/O Systems
- Takes an app's I/O request and seds it to the physical device, then sends response back to the application
    - This should be optimized
    - 2.0GHz takes 2ns
    - HDD seek time: 10ms
    - SSD seektime: 0.8ms
    - DDR3-1333 9-9-9 latency of 13.5ns
    - Add  commincation tie...
Recall