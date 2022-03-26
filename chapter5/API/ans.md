# 1. Using the fork 
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int x = 1;
    int rc = fork();
    wait(NULL);
    x++;
    x++;
    int *p = &x;
    if(rc == 0) printf("This is in the child process\n");
    else printf("This is the parent child\n");
    printf("x is %d\nThe address of the x is 0X%p\n",x,p);
    printf("\n");
}
```
If you change the varible in the son process ot the current process, it will not effect the other. 


# 2. using fork to write
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() {
    int rc = fork();
    FILE *p = fopen("./out.txt","w");
    wait(NULL);
    fprintf(p,"%d hello fork:%d",getpid(),rc);
}
```
The result is that the only the result of the child process can be shown. 

# 3. print the hello world with the son and the current process 
You can use the sleep

# 5 
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int c = fork();
    if(c > 0) {
        wait(NULL);
        printf("It is in the parent pid\n"); 
    }
    else {
        int ge = wait(NULL);
        printf(" son is %d\n",getpid());
        printf("the wait get %d\n",ge);
    }
}
```
The son will still go the first,and the ge is  -1


## 6 
if you use the pidwait(0) is will waiting for the son process to run. 

## 7
It will not ouput.It will be input to the block cache. 

## 8


