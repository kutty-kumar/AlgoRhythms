/*
 Created by kumard on 24/4/18.
*/

#ifndef ALGORHYTHMS_UTILS_H
#define ALGORHYTHMS_UTILS_H

#include <cstdio>

void printArray(int *input, int len){
    for(int i=0;i<len;i++){
        std::printf("%d ",input[i]);
    }
    std::printf("\n");
}
#endif //ALGORHYTHMS_UTILS_H
