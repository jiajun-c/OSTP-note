# The chapter6 
## 1. The basic skill 
The os expected the when the start programm running, it will create a 进程条目在进程列表。
Alocate some ram for it and the load the code to the ram. 

## 2. The restricted operation
Sometime the programm wants to execulte some restricted operation. 
(like the more I/O from the disk or ask for more cpu/ram)

At the same time, the system can not make the progress control it completely. 

The hardware provide different mode for the user 
- user mode, it can only get part of the resource, in the user mode, the user can not make I/O request 
- kernel mode, the user can get all of the rescource . It can. 

Under the user mode, if the user wants to make I/O request or else. It should 
execulte the special trap command. The request will jump to the kernel and prompt 
the level to the kernel mode. 

== keyword ==: how can the system get the control back. 

### The cooperation
For the most of the process, it will use the system call to back the control. 

If the process try some inlegal operation.The os will regain control.(Like divide the 
number with 0 or the unvisitable ram)

### The uncooperation mode 
The timer interrupt . After some fixed time(usual some ms), the system will make a interruption. The interrupt handler will start and the os will 
regain the control. 


