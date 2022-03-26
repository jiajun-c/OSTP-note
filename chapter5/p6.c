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
