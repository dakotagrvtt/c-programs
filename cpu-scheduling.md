**CPU-burst** - Amount of time the process uses the processor before it is no longer ready

**Timeslice** - discrete, finite unit of time (seconds).
* For cpu-scheduling, equal time slices are called quanta (plural of quantum).

**Context switch** - process in which the context of the current proces is saved, the CPU is deallocated from that process, and allocated to a new process (and new context is loaded). Significantly expensive operation.

**Scheduling policies**
- Non-preemptive - Process executes until CPU burst is complete
- Preemptive - Process can be interrupted while executing
	- Time slice expires
	- Higher priority may be in ready queue

**Throughput** - Number of processes executed and completed in a certain time period

**FCFS** - 1st come, 1st serve (waiting in DMV line)
**SJF** - Shortest job first
- CPU does not know how long a burst will last

**RR - Round Robin**
- if there is a process that arrives, it's added to run queue
- if process is running, it's added to back of queue
- to decide next running process, check the run queue
- PRO: Benefits short burst processes greatly
	-	Can hurt long burst processes
		-	Doesn't excessively penalize them; they will not starve
	- Preemptive
	- Slightly faster than FCFS
	- Turnaround time: Same as FCFS
	- Simple to implement, just statically implemented queue
- CON: This is context switching, which is EXPENSIVE

**SRT** - Shortest remaining time
- Long jobs may never get a chance to run.
- Not fair, needs est of burst time.
- Process must have an expected remaining time
	- If estimation time is bad, then *oops*
- As optimal as can be
	- Wait time is very low
	- Turnaround time is average

**Linux Implementation**
- Uses red black tree
- Default scheduler for the Linux kernel since the 2.6.23 release
- Uses nanosecond granularity
- Does not need heuristics to determine the interactivity of a process
	- how often it hits up I/O

***Avg wait:*** Wait time / # of processes
***Avg turnaround time:*** Wait time + Burst time / # of processes
