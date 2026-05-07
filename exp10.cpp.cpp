
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of elements you want to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal (Left Root Right): ";
    inorder(root);

    cout << "\nPreorder Traversal (Root Left Right): ";
    preorder(root);

    cout << "\nPostorder Traversal (Left Right Root): ";
    postorder(root);

    cout << endl;

    return 0;
}