/*
 Created by kumard on 24/4/18.
*/

#ifndef ALGORHYTHMS_DIVIDEANDCONQUER_H
#define ALGORHYTHMS_DIVIDEANDCONQUER_H

#include <tuple>
#include <climits>

std::pair<std::pair<int,int>,long> getMaxCrossingSubArray(int *input,int low,int mid,int high){
    int left_sum = INT_MIN,right_sum = INT_MIN,max_right= nullptr,max_left = nullptr;
    int sum = 0;
    for(int i=mid;i<=low;i--){
        sum+= input[i];
        if(left_sum < sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(int i =mid+1;i<high;i++){
        sum+=input[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    if(max_left == nullptr || max_right == nullptr){
        std::printf("Error finding max left and max right");
        exit(-1);
    }
    return std::make_pair(std::make_pair(max_left,max_right),left_sum+right_sum);
};




std::pair<std::pair<int,int>,long> getMaximumSubArray(int *input,int low,int high){
    if(low == high){
        return std::make_pair(std::make_pair(low,high),input[low]);
    }
    int mid = (low + high)/2;
    auto left = getMaximumSubArray(input,low,mid);
    auto right = getMaximumSubArray(input,mid+1,high);
    auto cross = getMaxCrossingSubArray(input,low,mid,high);
    if(left.second >= right.second && left.second >= cross.second){
        return left;
    }else if(right.second >= left.second && right.second >= cross.second){
        return right;
    }else{
        return cross;
    }
};

#endif //ALGORHYTHMS_DIVIDEANDCONQUER_H

