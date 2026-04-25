#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* top = nullptr;
int sizeStack = 0;

void push(int value) 
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    sizeStack++;
    cout << "pushed: " << value << endl;
}

void pop() 
{
    if (top == nullptr) 
    {
        cout << "Stack is underflow" << endl;
    } else 
    {
        cout << "poped = " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        sizeStack--;
    }
}

void peek() 
{
    if (top == nullptr) 
    {
        cout << "stack is empty" << endl;
    } else 
    {
        cout << "Top element = " << top->data << endl;
    }
}

void display() 
{
    if (top == nullptr) 
    {
        cout << "Stack Empty" << endl;
        return;
    }
    cout << "Stack : ";
    Node* curr = top;
    while (curr != nullptr) 
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() 
{
    int choice, value;

    do {
        cout << "\nEnter Which operation you perform :" << endl;
        cout << "1. Push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } 
    while (choice != 0);

    while (top != nullptr) 
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    return 0;
}
