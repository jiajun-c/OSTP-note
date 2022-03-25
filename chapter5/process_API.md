# The API of the process
# fork ,vfork ,wait and exec in the linux system

## fork()
In the fork, the system call to create a child process.
If you wants to use it
```c
#include <sys/types.h>
#include <unistd.h>
```
`pid_t fork(void)`

The child and the father process will run in the diferent memory spaces. At the time
of fork both memory spaces have the same content .

It will not inherit most of the things in his father.

It will return the pid of the son process to the parent process, and the 0 to itself
If it is error ,it will return -1.

## vfork()
The vfork is diferent, it will inherit the global varible.But the local varible will not
be inheit.
Take this code for example.
```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int a = 1;
int main() {
    int b = 1;
    vfork();
    a++;b++;
    printf("a: %d b: %d\n",a,b);
}
```
The output is
```shell
[Compile] ['gcc', '-o', '/tmp/vf2nVUF/7', '-std=c11', '-xc', '-', 'STDIN']
[Running] /tmp/vf2nVUF/7

--------------------
<stdin>: In function ‘main’:
<stdin>:7:5: warning: implicit declaration of function ‘vfork’; did you mean ‘fork’? [-Wimplicit-function-declaration]
a: 2 b: 2
a: 3 b: 32706

[Done] exited with code=0 in 0.060203 seconds
```

If you use the fork instead ,the output will be.
```shell
a 2 b 2
a 2 b 2
```
It will inherit the loacl varible, but will not be effect by the parent/son pid.


## wait
The waiting will suspend the current until the child has exited or until a signal
has delivered whoso ation is to terminate the current process or call the signal handler.

When you use the wait, you can get the fixed answer.

## exec
The exec is a useful function that can helps you running a different process in the current process.

In the exec, the exec function will be replace the current process.

So it you use the exec successfully,it will not return , as it is totally repalced the current process with the
same pid.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    printf("This prcoess is %d\n",getpid());
    char *use[] = {"/home/halfstar/note/OSTP/chapter5/get",NULL};
    execv(use[0],use);
    printf("Ending\n");
    return 0;
}
```
The output is
```c
This process is 5888
You get it
```





