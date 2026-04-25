#include <iostream>
using namespace std;

int *arr;
int front = -1;
int rear = -1;
int size = 5;

void EnQueue(int data){
    if(rear == size - 1){
        cout << "The Queue is Full" << endl;
        return;
    }

    if(front == -1){
        front = 0;
    }

    rear++;
    arr[rear] = data;
    cout << data << " is Inserted" << endl;
}

void DeQueue(){
    if(front == -1 || front > rear){
        cout << "The Queue is Empty" << endl;
        return;
    }

    cout << arr[front] << " is Removed" << endl;
    front++;
}

void Display(){
    if(front == -1 || front > rear){
        cout << "The Queue is Empty" << endl;
        return;
    }

    cout << "arr = [ ";
    for(int i = front; i <= rear; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main(){
    int choice, data;

    cout << "Enter size of Queue: ";
    cin >> size;

    arr = new int[size];

    do{
        cout << "\n--- MENU ---" << endl;
        cout << "========================================" << endl;
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter element to insert: ";
                cin >> data;
                EnQueue(data);
                break;

            case 2:
                DeQueue();
                Display();
                break;

            case 3:
                Display();
                break;

            case 0:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    }while(choice != 0);

    delete[] arr;

    return 0;
}