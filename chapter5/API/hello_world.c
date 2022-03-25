#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() {
    FILE *p = fopen("./out.txt","wa");
    int rc = fork();
    if(rc == 0) fprintf(p,"hello ");
    else {
        sleep(2);
        fprintf(p,"world");
    }
}
