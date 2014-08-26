#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE

int main(){
    FILE* fp = popen("ps -eo pid,uname,comm | grep 'root' | awk 'BEGIN {OFS=\" init .\"} {print $1, $3}'", "r");;
    
    char path[256];
    int i = 1;
    
    while(fgets(path, 256, fp) != NULL){
        printf("%d: %s", i, path);
        i++;
    }
    
    pclose(fp);
}
