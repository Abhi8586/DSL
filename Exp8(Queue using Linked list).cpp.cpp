#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value) 
{
    Node* node = new Node(value);
    if (!rear) 
    {
        front = rear = node;
    } else 
    {
        rear->next = node;
        rear = node;
    }
    cout << value << " inserted\n";
}

void dequeue() 
{
    if (!front) 
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << front->data << " removed\n";
    Node* temp = front;
    front = front->next;
    if (!front) 
    {
        rear = nullptr;
    }
    delete temp;
}

void display() 
{
    if (!front) 
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    for (Node* current = front; current; current = current->next) 
    {
        cout << current->data << " ";
    }
    cout << "\n";
}

int main() 
{
    int choice;

    while (true) 
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) 
        {
            break;
        }

        switch (choice) 
        {
            case 1: {
                int value;
                cout << "Enter element: ";
                cin >> value;
                enqueue(value);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
