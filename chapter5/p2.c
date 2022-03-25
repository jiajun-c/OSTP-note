#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv) {
    printf("PID is %d\n",(int)getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr,"fork fail\n");
        exit(0);
    }
    else if (rc == 0) {
        printf("hello,I'm child of the %d\n",getpid());
    }
    else {
        int wc = wait(NULL);
        printf("I'm the parent of the (%d), wait(%d),pid(%d)\n",rc,wc,getpid());
    }
}
