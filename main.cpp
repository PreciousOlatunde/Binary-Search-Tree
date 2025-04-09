//main.cpp
#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

//function prototypes
Node* buildBST(int* arr, int size);
void inorderPrint(Node* t);
void inorderTraverse(Node* r, int* arr);
int findK(Node* r, int k);
void printTreeIndented(Node* root, int level);

//main function
int main(){

    int arr[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    int size = sizeof(arr) / 4;
    Node* t = buildBST(arr, size);

    int k = -1;
    std::cout << "Enter a value for k to find the k-th smallest number: ";
    std::cin >> k;
    while (k <= 0 || k > size){
        std::cout << "Invalid value for k. Enter a number between 1 and " << size << " inclusive: ";
        std::cin >> k;
    }
    int kSmallest = findK(t, k);
    std::cout << "The " << k << "-th smallest number is " << kSmallest << std::endl;

    std::cout << "In-order traversal: ";
    inorderPrint(t);
    std::cout << std::endl;

    std::cout << "Indented format:" << std::endl;
    printTreeIndented(t, 0);
    std::cout << std::endl;

    return 0;
}

//function to build a Binary Search tree from array
Node* buildBST(int* arr, int size){
    int half = size / 2;
    Node* root = new Node(arr[half]);
    if(half >= 1){
        root->left = buildBST((arr), half);
        root->right = buildBST((arr+(half+1)), half);
    }

    return root;
}

// prints the binary search tree in in-order format
void inorderPrint(Node* t){
    if(t == NULL){
        return;
    }
    inorderPrint(t->left);
    std::cout << t->value << " ";
    inorderPrint(t->right);
}

//in-order traversak through the BST
void inorderTraverse(Node* r, std::vector<int>& arr){
    if(r == NULL){
        return;
    }

    inorderTraverse(r->left, arr);
    arr.push_back(r->value);
    inorderTraverse(r->right, arr);
}

//stores the values of the BST in-order and finds the k-th smallest element
int findK(Node* r, int k){
    std::vector<int> arr;
    inorderTraverse(r, arr);

    return arr[k - 1];
}

void printTreeIndented(Node* r, int level){
    if (r == nullptr)
        return;

    // print the right subtree first
    printTreeIndented(r->right, level + 1);

    // print the current node with indentation
    for (int i = 0; i < level; i++) {
        std::cout << "    ";  // Indent each level
    }
    std::cout << r->value << std::endl;

    // print the left subtree last
    printTreeIndented(r->left, level + 1);
}