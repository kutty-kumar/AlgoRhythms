#include <iostream>
#include "DynamicProgramming.h"
#include "Sorting.h"
#include "Utils.h"
#include "BinaryTrees.h"
#include "Searching.h"

using namespace std;
node root;

int main() {
    long long int input;
    cout << "Enter N: \n";
    cin >> input;
    cout << "Overlapping Sub Problem Factorial of " << input << " is: " << overlappingFactorial(input) << endl;
    cout << "Dynamic Programming Factorial of " << input << " is: " << dynamicFactorial(input) << endl;
    int input1[]{9, 2, 3, 4, 5};
    int input2[]{2,3,4,5,6,10};
    int len2 = sizeof(input2) / sizeof(int);
    int len1 = sizeof(input1) / sizeof(int);
    cout << "Linear search for 4: " << linearSearch(input1,len1,4) << endl;
    cout << "Binary Search for 10: "<< binarySearch(input2,0,len2,10) << endl;
    cout << "Before HeapSort Sort\n";
    printArray(input1, len1);
    heapSort(input1, len1);
    cout << "After HeapSort Sort\n";
    printArray(input1, len1);
    int choice;
    while (1) {
        cout << "Please select an option: \n";
        cout << "1: Insert\n2: Display\n3: Delete\n4: PreOrder Traversal\n5: InOrder Traversal\n"
                "6: PostOrder Traversal\n7: LevelOrder Traversal\n8: Spiral Traversal\n";
        cin >> choice;
        switch (choice) {
            case 1:
                int temp;
                cout << "Please Enter the number to be inserted\n";
                cin >> temp;
                root = insertNode(root, temp);
                break;
            case 2:
                displayTree(root, 0);
                break;
            case 3:
                cout << "Please Enter the node to be deleted from the tree\n";
                cin >> temp;
                root = deleteNode(root, temp);
                break;
            case 4:
                iterativePreOrder(root);
                printf("\n");
                break;
            case 5:
                iterativeInorder(root);
                printf("\n");
                break;
            case 6:
                iterativePostorder(root);
                printf("\n");
                break;
            case 7:
                levelOrderTraversal(root);
                break;
            case 8:
                spiralLevelTraversal(root);
                break;
            default:
                cout << "Sorry that input was not recognised\n";
                exit(0);
        }
    }
}
