#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree from array
Node* buildTree(vector<int>& arr, int i) {
    if (i >= arr.size())
        return NULL;

    Node* root = new Node(arr[i]);

    root->left = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i + 2);

    return root;
}

// Display tree (sideways)
void printTree(Node* root, int space = 0, int gap = 5) {
    if (root == NULL)
        return;

    space += gap;

    printTree(root->right, space);

    cout << endl;
    for (int i = gap; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    printTree(root->left, space);
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   Node* root = buildTree(arr, 0);
    cout << "\nTree Structure:\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    printTree(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
