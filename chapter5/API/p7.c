#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int rc = fork();
    if(rc == 0) {
        fclose(stdout);
        printf("OKK");
    }

}
