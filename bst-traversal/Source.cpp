#include <vector>
#include <iostream>

using namespace std;

class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
};

BST::BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
}

void printArray(vector<int> array);
void inOrderTraverse(BST* tree, vector<int>& array);
void preOrderTraverse(BST* tree, vector<int>& array);
void postOrderTraverse(BST* tree, vector<int>& array);

int main()
{
    BST* root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->right = new BST(22);

   

    vector<int> actualInOrder;
    vector<int> actualPreOrder;
    vector<int> actualPostOrder;

    inOrderTraverse(root, actualInOrder);
    printArray(actualInOrder);
    preOrderTraverse(root, actualPreOrder);
    printArray(actualPreOrder);
    postOrderTraverse(root, actualPostOrder);
    printArray(actualPostOrder);

   


    return 0;
}

void inOrderTraverse(BST* tree, vector<int>& array) {
    // Write your code here.
    if (tree != nullptr)
    {
        inOrderTraverse(tree->left, array);
        array.push_back(tree->value);
        inOrderTraverse(tree->right, array);
    }
}

void preOrderTraverse(BST* tree, vector<int>& array) {
    // Write your code here.
    if (tree != nullptr)
    {
        array.push_back(tree->value);
        preOrderTraverse(tree->left, array);
        preOrderTraverse(tree->right, array);
    }
}

void postOrderTraverse(BST* tree, vector<int>& array) {
    // Write your code here.
    if (tree != nullptr)
    {

        postOrderTraverse(tree->left, array);
        postOrderTraverse(tree->right, array);
        array.push_back(tree->value);
    }
}

void printArray(vector<int> array)
{
    for (int number : array)
    {
        cout << number << " ";
    }

    cout << endl;
}