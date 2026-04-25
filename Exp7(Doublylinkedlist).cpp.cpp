#include <iostream>

struct Node 
{
    int data;
    Node* prev;
    Node* next;

    Node(int value)
        : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList 
{
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insert(int data) 
    {
        Node* newNode = new Node(data);
        if (!head) 
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int key) 
    {
        Node* temp = head;
        while (temp) 
        {
            if (temp->data == key) 
            {
                if (!temp->prev) 
                {
                    head = temp->next;
                    if (head) 
                    {
                        head->prev = nullptr;
                    }
                } 
                else 
                {
                    temp->prev->next = temp->next;
                    if (temp->next) 
                    {
                        temp->next->prev = temp->prev;
                    }
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Value not found\n";
    }

    void display() const 
    {
        Node* temp = head;
        while (temp) 
        {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "null\n";
    }

    int addition() const 
    {
        int sum = 0;
        Node* temp = head;
        while (temp) 
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int subtraction() const 
    {
        if (!head) 
        {
            return 0;
        }
        int result = head->data;
        Node* temp = head->next;
        while (temp) 
        {
            result -= temp->data;
            temp = temp->next;
        }
        return result;
    }

    int multiplication() const 
    {
        if (!head) 
        {
            return 0;
        }
        int result = 1;
        Node* temp = head;
        while (temp) 
        {
            result *= temp->data;
            temp = temp->next;
        }
        return result;
    }

    double division() const 
    {
        if (!head) 
        {
            return 0.0;
        }
        double result = static_cast<double>(head->data);
        Node* temp = head->next;
        while (temp) 
        {
            if (temp->data == 0) 
            {
                std::cout << "Division by zero not allowed\n";
                return 0.0;
            }
            result /= temp->data;
            temp = temp->next;
        }
        return result;
    }
};

int main() 
{
    DoublyLinkedList list;

    list.insert(10);
    list.insert(5);
    list.insert(2);

    std::cout << "Doubly Linked List:\n";
    list.display();

    std::cout << "Addition: " << list.addition() << "\n";
    std::cout << "Subtraction: " << list.subtraction() << "\n";
    std::cout << "Multiplication: " << list.multiplication() << "\n";
    std::cout << "Division: " << list.division() << "\n";

    list.deleteNode(5);
    std::cout << "After Deletion:\n";
    list.display();

    return 0;
}
