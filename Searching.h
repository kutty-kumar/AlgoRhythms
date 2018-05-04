/*
 Created by kumard on 2/5/18.
*/

#ifndef ALGORHYTHMS_SEARCHING_H
#define ALGORHYTHMS_SEARCHING_H

int linearSearch(const int *input,int len,int x){
    for(int i=0;i<len;i++){
        if(input[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(const int *input,int low,int high,int x){
    if(low == high && input[low] != x){
        return -1;
    }
    while(low < high){
        int mid = (low + high)/2;
        if(input[mid] == x){
            return mid;
        }else if(input[mid] > x){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
}

#endif //ALGORHYTHMS_SEARCHING_H
