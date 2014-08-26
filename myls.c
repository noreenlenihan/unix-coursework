#define _GNU_SOURCE
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]){
    int opt;
    char* input;
    bool b = false;
    DIR* dp;
    struct stat st;
    
    
    while((opt = getopt(argc, argv, "l::")) != -1){
        switch(opt){
        case 'l': b = true;
                break;
        default: fprintf(stderr, "Usage: %s [-l] some directory\n", argv[1]);
        }
    }
    
   input = argv[optind];
   
   if(input != NULL){
        dp = opendir(argv[optind]);
    
    }
    else {
        dp = opendir("./");
    }
    
    struct dirent* ep;
        if(dp != NULL){
        while((ep = readdir(dp)) != NULL){
            if((strcmp(ep->d_name, ".")) == 0 || (strcmp(ep->d_name, "..")) == 0){
                continue;
            }
            if(b){
                lstat(ep->d_name, &st);
                if(ep->d_type == DT_DIR)
                    printf("d ");
                else if(ep->d_type == DT_LNK)
                    printf("l ");
                else if(ep->d_type == DT_REG)
                    printf("f ");
            }
            puts(ep->d_name);
        }
    closedir(dp);
    }
    
   return 0; 
}