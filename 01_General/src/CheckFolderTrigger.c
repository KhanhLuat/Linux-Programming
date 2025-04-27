#include <stdio.h>
#include "CheckFolderTrigger.h"
int CheckFolderTrigger(FILE *ptr){
    if(ptr != NULL){
        return 1;
    }else{
        return 0;
    }
}