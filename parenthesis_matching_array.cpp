#include<iostream>
using namespace std;

struct stack {
    char *arr;
    int top;
    int capacity;
};

stack* createStack(int capacity) {
    stack *ptr = new stack;
    ptr->capacity = capacity;
    ptr->arr = new char[capacity];
    ptr->top = -1;
    return ptr;
}

void push(stack *ptr, char data) {
    if (ptr->top == ptr->capacity - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

void pop(stack *ptr) {
    if (ptr->top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    ptr->top--;
}

void check(stack *ptr, string exp) {
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            push(ptr, exp[i]);
        }
        else if (exp[i] == ')') {
            if (ptr->top == -1) {
                cout << "Unbalanced" << endl;
                return;
            }
            pop(ptr);
        }
    }
    if (ptr->top == -1) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Unbalanced" << endl;
    }
}

int main() {
    stack *ptr = createStack(100); // Assuming maximum expression length is 100
    string exp = "(8+2)-(3))";
    check(ptr, exp);
    delete[] ptr->arr;
    delete ptr;
    return 0;
}
