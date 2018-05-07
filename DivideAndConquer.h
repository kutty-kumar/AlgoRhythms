/*
 Created by kumard on 24/4/18.
*/

#ifndef ALGORHYTHMS_DIVIDEANDCONQUER_H
#define ALGORHYTHMS_DIVIDEANDCONQUER_H

#include <tuple>
#include <climits>
#include "BinaryTrees.h"
#include "Sorting.h"


struct MaxMinPair{
    int min;
    int max;
};

std::pair<std::pair<int, int>, long> getMaxCrossingSubArray(int *input, int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN, max_right = NULL, max_left = NULL;
    int sum = 0;
    for (int i = mid; i <= low; i--) {
        sum += input[i];
        if (left_sum < sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i < high; i++) {
        sum += input[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    if (max_left == NULL || max_right == NULL) {
        std::printf("Error finding max left and max right");
        exit(-1);
    }
    return std::make_pair(std::make_pair(max_left, max_right), left_sum + right_sum);
};


std::pair<std::pair<int, int>, long> getMaximumSubArray(int *input, int low, int high) {
    if (low == high) {
        return std::make_pair(std::make_pair(low, high), input[low]);
    }
    int mid = (low + high) / 2;
    auto left = getMaximumSubArray(input, low, mid);
    auto right = getMaximumSubArray(input, mid + 1, high);
    auto cross = getMaxCrossingSubArray(input, low, mid, high);
    if (left.second >= right.second && left.second >= cross.second) {
        return left;
    } else if (right.second >= left.second && right.second >= cross.second) {
        return right;
    } else {
        return cross;
    }
};

int median(int *input, int len) {
    if (len % 2 == 0) {
        return (input[len / 2] + input[len / 2 - 1]) / 2;
    }
    return input[len / 2];
}

int medianOfTwoArrays(int *input1, int *input2, int len) {
    if (len <= 0) {
        return -1;
    }
    if (len == 1) {
        return (input1[0] + input2[0]) / 2;
    }
    if (len == 2) {
        return (max(input1[0], input1[1]) + max(input2[0], input2[1])) / 2;
    }

    int m1 = median(input1, len);
    int m2 = median(input2, len);

    if (m1 == m2) {
        return m1;
    }

    if (m2 > m1) {
        if (len % 2 == 0) {
            return medianOfTwoArrays(input1 + (len / 2) - 1, input2, len - (len / 2) - 1);
        }
        return medianOfTwoArrays(input1 + len / 2, input2, len - len / 2);
    }
    if (len % 2 == 0) {
        return medianOfTwoArrays(input2 + len / 2 - 1, input1, len - len / 2 - 1);
    }
    return medianOfTwoArrays(input2 + len / 2, input1, len - len / 2);
}

int min(int a,int b){
    return a < b ? a : b;
}

MaxMinPair findMaxMinPair(int *input,int len){
    MaxMinPair pair;
    if(len == 1){
        pair.max = input[0];
        pair.min = input[0];
        return pair;
    }else if(len == 2){
        pair.max = max(input[0],input[1]);
        pair.min = min(input[0],input[1]);
        return pair;
    }
    int mid = len/2;
    MaxMinPair lpair = findMaxMinPair(input,len - len/2);
    MaxMinPair rpair = findMaxMinPair(input+len/2,len - (len - len/2));
    if(lpair.max > rpair.max){
        pair.max = lpair.max;
    }else{
        pair.max = rpair.max;
    }

    if(lpair.min < rpair.min){
        pair.min = lpair.min;
    }else{
        pair.min = rpair.min;
    }
    return pair;
}

#endif //ALGORHYTHMS_DIVIDEANDCONQUER_H

