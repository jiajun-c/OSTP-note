#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
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
