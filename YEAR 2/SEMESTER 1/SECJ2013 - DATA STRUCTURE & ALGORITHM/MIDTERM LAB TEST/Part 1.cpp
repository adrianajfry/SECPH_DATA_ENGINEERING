#include <iostream>
#include <string>

class Email {
public:
    int id;
    std::string password;

    Email(int id = 0, std::string password = "") : id(id), password(password) {}
};

class Node {
public:
    Email email;
    Node* next;

    Node(Email email) : email(email), next(NULL) {}  // Fixed nullptr initialization
};

class ListEmail {
private:
    Node* head;

public:
    ListEmail() : head(NULL) {}

    void initialize() {
        head = NULL;
    }

    void addBack(Email email) {
        Node* newNode = new Node(email);
        if (head == NULL) {  // Fixed missing closing parenthesis
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteFront() {
        if (head == NULL) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            std::cout << "ID: " << current->email.id << ", Password: " << current->email.password << "\n";
            current = current->next;
        }
    }
};

int main() {
    ListEmail list;
    list.initialize();
    
    list.addBack(Email(1, "password1"));
    list.addBack(Email(2, "password2"));
    list.addBack(Email(3, "password3"));

    std::cout << "List after adding emails:\n";
    list.display();

    list.deleteFront();
    std::cout << "\nList after deleting the first email:\n";
    list.display();

    return 0;
}

