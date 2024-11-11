#include <iostream>
using namespace std;

class CircularDoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;

    CircularDoublyLinkedList() : head(nullptr) {}

    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void deleteAtBegin() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head->prev;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdl;
    cdl.insertAtBegin(1);
    cdl.insertAtEnd(2);
    cdl.insertAtEnd(3);
    cdl.display();
    cdl.deleteAtBegin();
    cdl.display();
    cdl.deleteAtEnd();
    cdl.display();
    return 0;
}
