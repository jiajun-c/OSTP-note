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
