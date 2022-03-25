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
