#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mystrcmp(const char* str1, const char* str2);

int mystrcmp(const char* str1, const char* str2){
    int i = 0;
    char c;
    char d;
    int result = 0;
    while((c = str1[i]) || (d = str2[i]) != '\0'){
        c = tolower(str1[i]);
        d = tolower(str2[i]);
        if(c != d){
            if(c > d){
                result = 1;
                break;
            }
            if(c < d){
                result = -1;
                break;
            }
        }
        else{
            result = 0;
            
        }
        i++;
    }
return result;
}