#include <iostream>
#include "DynamicProgramming.h"
#include "Sorting.h"
#include "Utils.h"
#include "BinaryTrees.h"
#include "Searching.h"
#include "DivideAndConquer.h"

using namespace std;
node root;

int main() {
   //          0,1,2,3,4,5,6,7
   int input[]{4,5,6,7,8,1,2,3};
   MaxMinPair pair = findMaxMinPair(input,sizeof(input)/sizeof(int));
   cout << pair.min << " : " << pair.max << endl;
   return 0;
}
