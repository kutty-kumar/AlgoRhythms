#include <iostream>
#include "DynamicProgramming.h"
using namespace std;

int main(){
    long long int input;
    cout<<"Enter N: \n";
    cin>>input;
    cout<<"Overlapping Sub Problem Factorial of "<<input<<" is: "<< overlappingFactorial(input)<<endl;
    cout<<"Dynamic Programming Factorial of "<<input<<" is: "<< dynamicFactorial(input)<<endl;
}