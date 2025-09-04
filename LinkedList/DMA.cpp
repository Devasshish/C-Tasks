#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // search for a value in the list
    void search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << endl << "Element " << key << " found in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << endl << "Element " << key << " not found." << endl;
    }

    // delete a node by value
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << endl << "List is empty." << endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << endl << "Node deleted." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << endl << "Value not found." << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << endl << "Node deleted." << endl;
    }

    // reverse  linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << endl << "List reversed." << endl;
    }

    // display linked list
    void display() {
        if (head == nullptr) {
            cout << endl << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    int choice, value;

    do {
        cout << endl << "--- Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Reverse List" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            ll.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            ll.search(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            ll.deleteNode(value);
            break;
        case 4:
            ll.reverse();
            break;
        case 5:
            ll.display();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
