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

int findMissingInteger(const int *input,int len){
    int xor1 = 1,xor2 = input[0];
    for(int i=2;i<len+1;i++){
        xor1 = xor1 ^ i;
    }

    for(int i=1;i<len;i++){
        xor2 = xor2 ^ input[i];
    }
    return xor1 ^ xor2;
}

/*
int main(){
    int input1[]{9, 2, 3, 4, 5};
    int input2[]{2,3,4,5,6,10};
    int len2 = sizeof(input2) / sizeof(int);
    int len1 = sizeof(input1) / sizeof(int);
    cout << "Linear search for 4: " << linearSearch(input1,len1,4) << endl;
    cout << "Binary Search for 10: "<< binarySearch(input2,0,len2,10) << endl;
}
*/
#endif //ALGORHYTHMS_SEARCHING_H
