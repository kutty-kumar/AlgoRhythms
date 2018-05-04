#include <iostream>
#include "DynamicProgramming.h"
#include "Sorting.h"
#include "Utils.h"
#include "BinaryTrees.h"
#include "Searching.h"

using namespace std;
node root;

int main() {
   int input[]{1,2,4,5};
   cout << findMissingInteger(input,sizeof(input)/sizeof(int));
   return 0;
}
