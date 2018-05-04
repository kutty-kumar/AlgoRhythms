/*
 Created by kumard on 29/4/18.
*/

#ifndef ALGORHYTHMS_BINARYTREES_H
#define ALGORHYTHMS_BINARYTREES_H

#include <stdio.h>
#include <stack>
#include <queue>

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node *node;

node createNode() {
    node item = (node) malloc(sizeof(Node));
    item->info = 0;
    item->left = nullptr;
    item->right = nullptr;
    return item;
}

node insertNode(node root, int info) {
    node item = createNode();
    if (item == nullptr) {
        printf("Couldn't allocate memory for new node, out of memory\n");
        exit(-1);
    }
    item->info = info;
    if (root == nullptr) {
        return item;
    }
    node cur = root, prev = nullptr;
    while (cur != nullptr) {
        prev = cur;
        if (cur->info > info) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (prev->info > info) {
        prev->left = item;
    } else {
        prev->right = item;
    }
    return root;
}

node deleteNode(node root, int info) {
    if (!root) {
        printf("Empty Tree\n");
        return nullptr;
    }
    node cur, parent = nullptr;
    cur = root;
    while (cur != nullptr) {
        if (cur->info == info) {
            break;
        } else if (cur->info > info) {
            parent = cur;
            cur = cur->left;
        } else {
            parent = cur;
            cur = cur->right;
        }
    }

    if (cur == nullptr) {
        printf("%d is absent in the tree\n", info);
        return nullptr;
    }
    node q;
    if (cur->left != nullptr && cur->right != nullptr) {
        node temp = cur->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        temp->left = cur->left;
        q = cur->right;
    } else if (cur->left == nullptr && cur->right != nullptr) {
        q = cur->right;
    } else if (cur->left != nullptr && cur->right == nullptr) {
        q = cur->left;
    }
    if (parent == nullptr) {
        free(cur);
        return q;
    } else {
        if (parent->info > cur->info) {
            parent->left = q;
        } else {
            parent->right = q;
        }
    }
    free(cur);
    return root;
}


void displayTree(node root, int level) {
    if (root == nullptr) {
        return;
    }
    displayTree(root->right, level + 1);
    for (int i = 0; i <= level; i++) {
        printf(" ");
    }
    printf("%d\n", root->info);
    displayTree(root->left, level + 1);
}


void iterativePreOrder(node root) {
    if (root == nullptr) {
        return;
    }
    std::stack<node> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        node temp = nodeStack.top();
        printf("%d ", temp->info);
        nodeStack.pop();
        if (temp->left != nullptr) {
            nodeStack.push(temp->left);
        }
        if (temp->right != nullptr) {
            nodeStack.push(temp->right);
        }
    }
    printf("\n");
}

void iterativeInorder(node root) {
    if (root == nullptr) {
        return;
    }
    std::stack<node> nodeStack;
    node cur;
    bool done = false;
    cur = root;
    while (!done) {
        if (cur != nullptr) {
            nodeStack.push(cur);
            cur = cur->left;
        } else {
            if (!nodeStack.empty()) {
                node temp = nodeStack.top();
                printf("%d ", temp->info);
                nodeStack.pop();
                cur = temp->right;
            } else {
                done = true;
            }
        }
    }
    printf("\n");
}

void iterativePostorder(node root) {
    if (root == nullptr) {
        return;
    }
    std::stack<node> nodeStack;
    std::stack<node> nodeStack1;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        node temp = nodeStack.top();
        nodeStack1.push(temp);
        nodeStack.pop();
        if (temp->left != nullptr) {
            nodeStack.push(temp->left);
        }
        if (temp->right != nullptr) {
            nodeStack.push(temp->right);
        }
    }

    while (!nodeStack1.empty()) {
        node temp = nodeStack1.top();
        nodeStack1.pop();
        printf("%d ", temp->info);

    }
    printf("\n");
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(node root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return max(getHeight(root->left), getHeight(root->right));
    }
}

void levelOrderTraversal(node root) {
    if (root == nullptr) {
        return;
    }
    node temp_node;
    std::queue<node> nodeQueue;
    temp_node = root;
    while (temp_node != nullptr) {
        printf("%d ", temp_node->info);
        if (temp_node->left != nullptr) {
            nodeQueue.push(temp_node->left);
        }
        if (temp_node->right != nullptr) {
            nodeQueue.push(temp_node->right);
        }
        temp_node = nodeQueue.front();
        nodeQueue.pop();
    }
    printf("\n");
}

void printNodesInLevel(node root, int level, bool *flag) {
    if (level == 1) {
        printf("%d ", root->info);
    } else if (level > 1) {
        if (flag) {
            printNodesInLevel(root->left, level - 1, flag);
            printNodesInLevel(root->right, level - 1, flag);
        } else {
            printNodesInLevel(root->right, level - 1, flag);
            printNodesInLevel(root->left, level - 1, flag);
        }
    }
}

void spiralLevelTraversalRecursive(node root) {
    if (root == nullptr) {
        return;
    }
    int height = getHeight(root);
    bool flag = false;
    for (int i = 1; i <= height; i++) {
        printNodesInLevel(root, i, &flag);
        flag = ~flag;
    }
}

void spiralLevelTraversal(node root) {
    if (root == nullptr) {
        return;
    }
    std::stack<node> s1;
    std::stack<node> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            node temp = s1.top();
            printf("%d ", temp->info);
            s1.pop();
            if (temp->left != nullptr) {
                s2.push(temp->left);
            }
            if (temp->right != nullptr) {
                s2.push(temp->right);
            }
        }
        while (!s2.empty()) {
            node temp = s2.top();
            printf("%d ", temp->info);
            s2.pop();
            if (temp->left != nullptr) {
                s1.push(temp->left);
            }
            if (temp->right != nullptr) {
                s2.push(temp->right);
            }
        }
    }
    printf("\n");
}
/*
int main(){
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
    return 0;
}
 */

#endif //ALGORHYTHMS_BINARYTREES_H
