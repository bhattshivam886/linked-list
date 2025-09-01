#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // insert at end
    void insertAtEnd(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // insert at beginning
    void insertAtBeginning(int val) {
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }

    // delete by value
    void deleteNode(int val) {
        if (head == nullptr) return;

        // if head is target
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        Node* delete_node = temp->next;
        temp->next = temp->next->next;
        delete delete_node;
    }

    // display linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Initial List: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "After inserting 5 at beginning: ";
    list.display();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
