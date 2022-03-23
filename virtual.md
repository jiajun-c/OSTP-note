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


