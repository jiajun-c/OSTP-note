# The chapter 1 -- The introduction of the OS

## 1 The virtual cpu

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
int main(int argc,char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,"error");
        exit(0);
    }
    char *str = argv[1];
    while(1) {
       // Spin(1);
         sleep(1);
        printf("%s\n",str);
    }
}
```
dd#include <stdio.h>

If you run it like this

```shell
gcc -o cpu cpu.c -Wall
./cpu "A"
```
It will print "A" every second
If you execute it like this

```shell
./cpu "A" &; ./cpu "B"
```

It will output "A" and "B" alternatively. It seems like you have many cpu work at the same time .
In fact, in the further chapters of this book, it will discuss the similar things.

## 2. The virtial RAM

It is similar to the virtual cpu

```c
#include <stdio.h>                                                                                                                          
#include <stdio.h>                                                                                                                               
#include <stdlib.h>                                                                                                                              
#include <sys/time.h>                                                                                                                            
#include <assert.h>                                                                                                                              
#include <time.h>                                                                                                                                
#include <unistd.h>                                                                                                                             
#include <string.h>                                                                                                                              
#include <strings.h>                                                                                                                             
#include <stdbool.h>                                                                                                                             
int main(int argc,char *argv[]) {                                                                                                                
    int *p = malloc(sizeof(int));                                     
    assert(p!=NULL);                                                   
    printf("(%d) memory address of p: %08x\n",getpid(),(unsigned)p);    
    *p = 0;                                                                                                                                      
    while(1) {                                                                                                                                   
        sleep(1);                                                                                                                                
        *p = *p + 1;                                                                                                                            
        printf("(%d) p:%d\n",getpid(),*p);                                                                                                       
    }                                                                                                                                           
    return 0;                                                                                                                                   
}                                                                                                                                                
``` 

If it works many program at the same time, it will share the same memory

## 3. The concurrency

If you use manys threads at the same time. It will have some magic things.

## 4. The persistence 
The hard dirve is the normal way to storage the message.




