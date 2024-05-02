//STACK

//Write for peek(), searchbottom & top function 
#include <iostream>
using namespace std;
using std::string;

struct stack
{
    int *arr;
    int size;
    int top;
};
int isEmpty(stack *ptr)
{
    return ptr->top == -1;
}
int isFull(stack *ptr)
{
    return ptr->top == ptr->size - 1;
}
void push(stack *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        cout << "Inserted successfully" << endl;
    }
}
void pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        int var = ptr->arr[ptr->top];
        ptr->top--;
        cout << var << " is deleted from stack" << endl;
    }
}
void display(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        int i = ptr->top;
        while (i >= 0)
        {
            cout << ptr->arr[i] << endl;
            i--;
            ;
        }
    }
    cout << endl;
}
int main()
{
    struct stack *s = (stack *)malloc(sizeof(stack)); // so that the array can be passed by reference; s is a structure pointer
    s->size = 10;                                     // size of array
    s->top = -1;                                      // indicates
    s->arr = (int *)malloc(s->size * sizeof(int));
    int choice, data, option;
    while (choice)
    {
        cout << "Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "Choose an option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter data to be inserted: ";
            cin >> data;
            push(s, data);
            break;
        case 2:
            pop(s);
            break;
        // case 3:
        // cout<<"Enter data to be searched: ";
        // cin>>data;
        // search(arr,size,top,data);
        // break;
        case 4:
            display(s);
            break;
        default:
            cout << "Invalid option" << endl;
        }
        cout << "Do you want to continue?" << endl;
        cin >> choice;
    }
    return 0;
}