#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char **argv) {
    printf("hello world (pid:%d)\n",(int)getpid());
    int rc = fork();
    printf("pid:%d  rc:%d\n",getpid(),rc);
    if (rc < 0) printf("fork error\n");
    else if (rc == 0) printf("Hello, I'm the child of the (%d)\n",getpid());
    else printf("Hello,I'm the father of the (%d)\n",getpid());
}
