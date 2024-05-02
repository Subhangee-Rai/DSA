#include <iostream>
using namespace std;
using std::string;

struct stack
{
    int top;
    char *arr;
};
void push(stack *ptr, char data)
{
    ptr->top++;
    ptr->arr[ptr->top] = data;
}
void pop(stack *ptr)
{
    ptr->top--;
}
void check(stack *ptr, string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(ptr, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (ptr->top == -1)
            {
                cout << "Unbalanced" << endl;
                return;
            }
            char topChar = ptr->arr[ptr->top];
            if ((exp[i] == ')' && topChar == '(') ||
                (exp[i] == ']' && topChar == '[') ||
                (exp[i] == '}' && topChar == '{'))
            {
                pop(ptr);
            }
            else
            {
                cout << "Unbalanced" << endl;
                return;
            }
        }
    }
    if (ptr->top == -1)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }
}
int main()
{
    stack *ptr = new stack;
    ptr->top=-1;
    string exp = "(2+3)-[3*4]{5*6}]";
    check(ptr, exp);
    return 0;
}