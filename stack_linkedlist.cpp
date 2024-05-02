#include<iostream>
using namespace std;

struct stack {
    int data;
    stack* next;
};

stack* push(stack* top, int data) {
    stack* newn = new stack;
    newn->data = data;
    newn->next = nullptr;
    
    if (top == nullptr) {
        top = newn;
    } else {
        stack* cur = top;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newn;
    }
    
    cout << "Pushed Successfully" << endl;
    return top;
}

stack* pop(stack* top) {
    if (top == nullptr) {
        cout << "Underflow" << endl;
        return top;
    }
    
    stack* cur = top;
    top = top->next;
    delete cur;
    return top;
}

void search(stack* top, int element) {
    stack* cur = top;
    while (cur != nullptr && cur->data != element) {
        cur = cur->next;
    }
    if (cur != nullptr && cur->data == element) {
        cout << element << " found" << endl;
    } else {
        cout << element << " not found" << endl;
    }
}

void traverse(stack* top) {
    stack* cur = top;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    stack* top = nullptr;
    int choice = 1, option, data;
    while (choice) {
        cout << "MENU: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "Choose an option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                top = push(top, data);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                search(top, element);
                break;
            case 4:
                traverse(top);
                break;
            default:
                cout << "Invalid option!" << endl;
        }
        cout << "Do you want to continue? (0/1): ";
        cin >> choice;
    }
    return 0;
}
