#include <iostream>
using namespace std;

struct stack
{
    char data;
    struct stack *next;
};

stack *push(stack *head, char data)
{
    stack *newn = new stack;
    newn->data = data;
    newn->next = head;
    return newn;
}

stack *pop(stack *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    stack *cur = head;
    head = head->next;
    delete cur;
    return head;
}

void check(string exp, stack *&head) // The check function signature includes a reference to the head pointer to modify it within the function.
{
    int openingCount = 0;
    int closingCount = 0;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            head = push(head, exp[i]);
            openingCount++;
        }
        else if (exp[i] == ')')
        {
            head = pop(head);
            closingCount++;
            if (head == nullptr && closingCount > openingCount)
            {
                cout << "Unbalanced" << endl;
                return;
            }
        }
    }
    if (head == nullptr && openingCount == closingCount)
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
    stack *head = nullptr;
    string exp = "(8+2)-(3*9)";
    check(exp, head);
    return 0;
}
