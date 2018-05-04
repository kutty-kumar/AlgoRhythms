/*
 Created by kumard on 24/4/18.
*/

#ifndef ALGORHYTHMS_SORTING_H
#define ALGORHYTHMS_SORTING_H

#include <cstdio>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// mid should always be in the left array and the right array should always start from mid+1
void merge(int *input,int low,int mid,int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1],r[n2];

    for(int i=0;i<n1;i++){
        l[i]=input[low + i];
    }

    for(int i=0;i<n2;i++){
        r[i]=input[mid + 1 + i];
    }

    int i=0,j=0,k=low;
    while( i < n1 && j< n2){
        if(l[i]<r[j]){
            input[k++] = l[i++];
        }else{
            input[k++] = r[j++];
        }
    }

    while(i < n1){
        input[k++] = l[i++];
    }

    while(j < n2){
        input[k++] = r[j++];
    }
}

void mergeSort(int *input,int low,int high){
    if(high == low){
        return;
    }
    int mid = (low + high)/2;
    mergeSort(input,low,mid);
    mergeSort(input,mid+1,high);
    merge(input,low,mid,high);
}

void insertionSort(int *input,int len){
    for(int j=1;j<len;j++){
        int i = j-1;
        int key = input[j];
        while(i >=0 && key < input[i]){
            input[i+1] = input[i];
            i--;
        }
        input[i+1] = key;
    }
}

void selectionSort(int *input,int len){
    for(int i=0;i<len;i++){
        int min = input[i],key=i;
        for(int j=i+1;j<len;j++){
            if(input[j] < min){
                min = input[j];
                key = j;
            }
        }
      swap(&input[i],&input[key]);
    }
}

int partition(int *input,int low,int high){
    int x = input[high];
    int i = low-1;
    for(int j=low;j<=high-1;j++){
        if(x >= input[j]){
            i++;
            swap(&input[i],&input[j]);
        }
    }
    swap(&input[i+1],&input[high]);
    return i+1;
}

void quickSort(int *input,int low,int high){
    if(low < high){
        int q = partition(input,low,high);
        quickSort(input,low,q-1);
        quickSort(input,q+1,high);
    }
}

void maxheapify(int *input,int i,int heapSize){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(input[left] > input[i] && left < heapSize){
            largest = left;
        } else if(input[right] > input[i] && right < heapSize){
            largest = right;
        }
        if(largest != i){
            swap(&input[i],&input[largest]);
            maxheapify(input,largest,heapSize);
        }
}


void heapSort(int *input,int len){
    for(int i=(len/2)-1;i>=0;i--){
        maxheapify(input,i,len);
    }
    for(int i=len-1;i>=0;i--){
        swap(&input[0],&input[i]);
        maxheapify(input,0,i);
    }
}

/*
int main(){
    int input1[]{9, 2, 3, 4, 5};
    int len1 = sizeof(input1) / sizeof(int);
    cout << "Before HeapSort Sort\n";
    printArray(input1, len1);
    heapSort(input1, len1);
    cout << "After HeapSort Sort\n";
    printArray(input1, len1);
}
*/
#endif //ALGORHYTHMS_SORTING_H
