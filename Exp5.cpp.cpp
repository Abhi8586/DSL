#include <iostream>
using namespace std;

int *stackArr;
int top = -1;
int sizeStack;

void push(int value){
    if(top == sizeStack - 1){
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        stackArr[top] = value;
        cout << "pushed: " << value << endl;
    }
}

void pop(){
    if(top == -1){
        cout << "Stack is underflow" << endl;
    } else {
        cout << "poped = " << stackArr[top] << endl;
        top--;
    }
}

void peek(){
    if(top == -1){
        cout << "stack is empty" << endl;
    } else {
        cout << "Top element = " << stackArr[top] << endl;
    }
}

void display(){
    if(top == -1){
        cout << "Stack Empty" << endl;
        return;
    }

    cout << "Stack : ";
    for(int i = top; i >= 0; i--){
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter stack Size : ";
    cin >> sizeStack;

    stackArr = new int[sizeStack];

    int choice;
    int value;

    do{
        cout << "\nEnter Which operation you perform :" << endl;
        cout << "1. Push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice){
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

    }while(choice != 0);

    delete[] stackArr;
    return 0;
}
