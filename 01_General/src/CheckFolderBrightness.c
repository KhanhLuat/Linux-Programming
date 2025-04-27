#include <stdio.h>
#include "CheckFolderBrightness.h"
int CheckFolderBrightness(FILE *ptr){
    if(ptr != NULL){
        printf("Open the file path");
        return 1;
    }else{
        printf("Cannot open the file path");
        return 0;
    }
}