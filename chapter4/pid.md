# Abstract: process
[TOC]

In the chapter 2, we see the method to virtue memory. In this chapter, we will take about how to achieve it.

The time sharing is an important way to achieve it, every programm use the cpu for a while. And there are some policy to switch.

## 1. The concept of the process

The process is a programm running in the machine. 
It has the machine status, storge and the instruction point.

## 2. The API of the process 

- create  
- destory
- wait
- miscellaneous control
- status. Some tools in the commandline can help you get it. 


## 3. detail in creating the process 

#### 3.1 load the code
In the early pc, the os will load all of the code into the ram before running it .
In the modern pc, the os will load the code lazily .It means when programm needd 
to load more code or data, it will work.


## 4. The status of the process
- running: the process is running in the cpu
- ready: the process is ready to run, when the another process is running ,this process will be in the ready status. 
- blocked: a process is operating an operation, like an I/O, after this operation finished, the process will continue. 

When a process is blocked, another process can be running. 

## 5.The DS
The source code may be different from what you get from the book.
```c
00001 // Segments in proc->gdt.
00002 // Also known to bootasm.S and trapasm.S
00003 #define SEG_KCODE 1  // kernel code
00004 #define SEG_KDATA 2  // kernel data+stack
00005 #define SEG_KCPU  3  // kernel per-cpu data
00006 #define SEG_UCODE 4
00007 #define SEG_UDATA 5
00008 #define SEG_TSS   6  // this process's task state
00009 #define NSEGS     7
00010
00011 // Saved registers for kernel context switches.
00012 // Don't need to save all the segment registers (%cs, etc),
00013 // because they are constant across kernel contexts.
00014 // Don't need to save %eax, %ecx, %edx, because the
00015 // x86 convention is that the caller has saved them.
00016 // Contexts are stored at the bottom of the stack they
00017 // describe; the stack pointer is the address of the context.
00018 // The layout of the context must match the code in swtch.S.
00019 struct context {
00020   uint edi;
00021   uint esi;
00022   uint ebx;
00023   uint ebp;
00024   uint eip;
00025 };
00026
00027 enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
00028
00029 // Per-process state
00030 struct proc {
00031   char *mem;                   // Start of process memory (kernel address)
00032   uint sz;                     // Size of process memory (bytes)
00033   char *kstack;                // Bottom of kernel stack for this process
00034   enum procstate state;        // Process state
00035   volatile int pid;            // Process ID
00036   struct proc *parent;         // Parent process
00037   struct trapframe *tf;        // Trap frame for current syscall
00038   struct context *context;     // Switch here to run process
00039   void *chan;                  // If non-zero, sleeping on chan
00040   int killed;                  // If non-zero, have been killed
00041   struct file *ofile[NOFILE];  // Open files
00042   struct inode *cwd;           // Current directory
00043   char name[16];               // Process name (debugging)
00044 };
00045
00046 // Process memory is laid out contiguously, low addresses first:
00047 //   text
00048 //   original data and bss
00049 //   fixed-size stack
00050 //   expandable heap
00051
00052 // Per-CPU state
00053 struct cpu {
00054   uchar id;                    // Local APIC ID; index into cpus[] below
00055   struct context *scheduler;   // Switch here to enter scheduler
00056   struct taskstate ts;         // Used by x86 to find stack for interrupt
00057   struct segdesc gdt[NSEGS];   // x86 global descriptor table
00058   volatile uint booted;        // Has the CPU started?
00059   int ncli;                    // Depth of pushcli nesting.
00060   int intena;                  // Were interrupts enabled before pushcli?
00061
00062   // Cpu-local storage variables; see below
00063   struct cpu *cpu;
00064   struct proc *proc;
00065 };
00066
00067 extern struct cpu cpus[NCPU];
00068 extern int ncpu;
00069
00070 // Per-CPU variables, holding pointers to the
00071 // current cpu and to the current process.
00072 // The asm suffix tells gcc to use "%gs:0" to refer to cpu
00073 // and "%gs:4" to refer to proc.  ksegment sets up the
00074 // %gs segment register so that %gs refers to the memory
00075 // holding those two variables in the local cpu's struct cpu.
00076 // This is similar to how thread-local variables are implemented
00077 // in thread libraries such as Linux pthreads.
00078 extern struct cpu *cpu asm("%gs:0");       // This cpu.
00079 extern struct proc *proc asm("%gs:4");     // Current proc on this cpu.
```





