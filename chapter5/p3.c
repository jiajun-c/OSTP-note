#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    printf("This prcoess is %d\n",getpid());
    char *use[] = {"/home/halfstar/note/OSTP/chapter5/get",NULL};
    execv(use[0],use);
    printf("Ending\n");
    return 0;;

}
