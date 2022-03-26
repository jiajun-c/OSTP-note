#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pi[2];
    int p = pipe(pi);
    int rc[2];
    char buf[128];
    if(p < 0) printf("pipe error\n");
    for (int i = 0;i < 2;i++) {
        printf("i = %d\n",i);
        rc[i] = fork();
        if (rc[i] == 0&&i == 0) {
            printf("The write pid is %d\n",getpid());
            close(pi[0]);
            write(pi[1],"Input from it",14);
        }
        if (rc[i] == 0&&i == 1) {
            printf("The read pid is %d\n",getpid());
            close(pi[1]);
            read(pi[0],buf,20);
            fprintf(stderr,"%s\n",buf);
        }
    }
}
