/*
 Created by kumard on 2/5/18.
*/

#ifndef ALGORHYTHMS_SEARCHING_H
#define ALGORHYTHMS_SEARCHING_H

#include <climits>

int linearSearch(const int *input, int len, int x){
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
    int i;
    int x1 = input[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */

    for (i = 1; i< len; i++)
        x1 = x1^input[i];

    for ( i = 2; i <= len+1; i++)
        x2 = x2^i;

    return (x1^x2);
}

// 4 5 6 7 8 1 2 3

int findPivot(int *input,int low,int high){
    if(low > high){
        return -1;
    }
    if(low == high){
        return low;
    }
    int mid = (low + high)/2;
    if(mid+1 < high && input[mid] > input[mid+1]){
        return mid;
    }
    if(mid-1 > low && input[mid-1] > input[mid]){
        return mid-1;
    }
    if(input[mid] < input[mid+1] && input[mid] > input[mid-1]){
        return findPivot(input,low,mid-1);
    }else{
        return findPivot(input,mid+1,high);
    }
}

int searchSortedRotatedArray(int *input,int low,int high,int key){
    int pivot = findPivot(input,low,high);
    if(pivot == -1){
        return binarySearch(input,low,high,key);
    }
    if(input[pivot] == key){
        return pivot;
    }
    if(input[0] <= key){
        return binarySearch(input,low,pivot-1,key);
    }else{
        return binarySearch(input,pivot+1,high,key);
    }
}


std::pair<int, int> elementsSumCloseToZ0(int *input, int len) {
    quickSort(input, 0, len);
    int l = 0, r = len - 1, sum, min_sum = INT_MAX, min_l = l, min_r = r;
    while (l < r) {
        sum = input[l] + input[r];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if (sum < 0) {
            l++;
        } else {
            r--;
        }
    }
    return std::make_pair(min_l, min_r);
}


std::pair<int,int> find2Smallest(int *input, int len) {
    int first,second=INT_MAX;
    for (int i = 0; i < len; i++) {
        if(input[i] < first){
            second = first;
            first = input[i];
        }else if(input[i] < second && input[i] > first){
            second = input[i];
        }
    }
    return std::make_pair(first,second);
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
