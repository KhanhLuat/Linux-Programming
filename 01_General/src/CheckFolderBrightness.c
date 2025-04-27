#include <stdio.h>
#include "CheckFolderBrightness.h"
int CheckFolderBrightness(FILE *ptr){
    if(ptr != NULL){
        printf("Ok\n");
        return 1;
    }else{
        printf("Cannot open the file path");
        return 0;
    }
}