#include <iostream>
using namespace std;
using std::string;

struct queue
{
    int data;
    queue *next;
};
queue *enqueue(queue *head, int data)
{
    queue *newn = new queue;
    newn->data = data;
    newn->next = nullptr;
    if (head == nullptr)
    {
        return newn;
    }
    else
    {
        newn->next = head;
        head = newn;
        return head;
    }
}
queue *dequeue(queue *head)
{
    if (head == nullptr)
    {
        cout << "Nothing to delete" << endl;
        return nullptr;
    }
    else
    {
        queue *cur = new queue;
        cur = head;
        head = head->next;
        delete cur;
        cout << "Deleted" << endl;
        return head;
    }
}
void display(queue *head)
{
    if (head == nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
    else
    {
        queue *cur = new queue;
        cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }
    }
}
int main()
{
    queue *head = nullptr;
    int ch, option, data;
    while (ch)
    {
        cout << "MENU" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice:";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the value of node: ";
            cin >> data;
            head = enqueue(head, data);
            /* code */
            break;
        case 2:
            head = dequeue(head);
            break;
        case 3:
            display(head);
            break;
        default:
            break;
        }
    }
    return 0;
}