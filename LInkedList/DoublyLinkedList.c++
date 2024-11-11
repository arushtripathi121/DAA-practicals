#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBegin() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        if (temp->prev) temp->prev->next = nullptr;
        if (temp == head) head = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBegin(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.display();
    dll.deleteAtBegin();
    dll.display();
    dll.deleteAtEnd();
    dll.display();
    return 0;
}
