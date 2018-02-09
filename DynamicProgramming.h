//
// Created by Kumar D on 09/02/18.
//
#ifndef ALGORITHMS_DYNAMICPROGRAMMING_H
#define ALGORITHMS_DYNAMICPROGRAMMING_H
long long int overlappingFactorial(long long int n){
    if(n==0 || n==1){
        return 1;
    }
    return n* overlappingFactorial(n - 1);
}

long long int dynamicFactorial(long long int n){
    long long int factorailArray[n+1];
    factorailArray[0] = 1;
    factorailArray[1] = 1;
    for(int i=2;i<n+1;i++){
        factorailArray[i]=i*factorailArray[i-1];
    }
    return factorailArray[n];
}



#endif //ALGORITHMS_DYNAMICPROGRAMMING_H
