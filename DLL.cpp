#include <iostream>
using namespace std;
using std::string;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
node *insert_at_front(node *head, int data)
{
    node *newn = new node;
    newn->data = data;
    newn->prev = nullptr;
    newn->next = nullptr;
    if (head == nullptr)
    {
        return newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
        return head;
    }
}
node *insert_at_end(struct node *head, int data)
{
    node *newn = new node;
    newn->data = data;
    newn->next = nullptr;
    newn->prev = nullptr;
    if (head == nullptr)
    {
        return newn;
    }
    else
    {
        node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newn;
        newn->prev = cur;
        return head;
    }
}
node *insert_at_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->prev = nullptr;
    newn->next = nullptr;
    if (head == nullptr)
    {
        cout << "Empty list. You want to enter at first position?" << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            return newn;
        }
    }
    else
    {
        node *cur = head;
        node *prv = nullptr;
        int count = 1;
        while (cur != nullptr && count < pos)
        {
            prv = cur;
            cur = cur->next;
            count++;
        }
        newn->next = cur;
        cur->prev = newn;
        prv->next = newn;
        newn->prev = prv;
        return head;
    }
}
node *insert_after_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->prev = nullptr;
    newn->next = nullptr;
    if (head == nullptr)
    {
        cout << "Empty list. You want to enter at first position?" << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            return newn;
        }
    }
    else
    {
        node *cur = head;
        node *prv = nullptr;
        int count = 1;
        while (cur != nullptr && count <= pos)
        {
            prv = cur;
            cur = cur->next;
            count++;
        }
        newn->next = cur;
        cur->prev = newn;
        prv->next = newn;
        newn->prev = prv;
        return head;
    }
}
node *insert_before_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->prev = nullptr;
    newn->next = nullptr;
    if (head == nullptr)
    {
        cout << "Empty list. You want to enter at first position?" << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            return newn;
        }
    }
    else
    {
        node *cur = head;
        node *prv = nullptr;
        int count = 1;
        while (cur != nullptr && count < pos)
        {
            prv = cur;
            cur = cur->next;
            count++;
        }
        newn->next = cur;
        cur->prev = newn;
        prv->next = newn;
        newn->prev = prv;
        return head;
    }
}
node *delete_at_front(node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return head;
    }
    else if (head->next == nullptr)
    {
        delete head;
        cout << "Node deleted successfully" << endl;
        return nullptr;
    }
    else
    {
        node *cur = head;
        head = head->next;
        delete cur;
        cout << "Successfully deleted" << endl;
        return head;
    }
}
node *delete_at_end(node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return head;
    }
    else if (head->next == nullptr)
    {
        delete head;
        cout << "Node deleted successfully" << endl;
        return nullptr;
    }
    else
    {
        node *cur = head;
        node *prv;
        while (cur->next!= nullptr)
        {
            prv = cur;
            cur = cur->next;
        }
        prv->next = nullptr;
        cout << "Deleted successfully" << endl;
        delete cur;
        return head;
    }
}
node *delete_at_pos(node *head,int pos)
{
    if(head==nullptr)
    {
        cout<<"Empty list"<<endl;
        return head;
    }
    else if (head->next == nullptr && pos == 1)
    {
        delete head;
        cout << "Node deleted successfully" << endl;
        return nullptr;
    }
    else{
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        while(cur!=nullptr&&count<pos)
        {
            prv=cur;
            cur=cur->next;
            count++;
        }
        prv->next=cur->next;
        cur->next->prev=prv->next;
        delete cur;
        cout<<"Deleted Successfully"<<endl;
        return head;
    }
}
node *delete_after_pos(node *head,int pos)
{
    if(head==nullptr)
    {
        cout<<"Empty list"<<endl;
        return head;
    }
    else if (head->next == nullptr)
    {
        int choice;
        cout << "Only one node to delete, Do you want to delete it?" << endl;
        cin >> choice;
        if (choice == 1)
        {
            delete head;
            cout << "Node deleted successfully" << endl;
            return nullptr;
        }
    }
    else{
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        while(cur!=nullptr&&count<=pos)
        {
            prv=cur;
            cur=cur->next;
            count++;
        }
        prv->next=cur->next;
        cur->next->prev=prv->next;
        delete cur;
        cout<<"Deleted Successfully"<<endl;
        return head;
    }
}
node *delete_before_pos(node *head,int pos)
{
    if(head==nullptr)
    {
        cout<<"Empty list"<<endl;
        return head;
    }
    else if (head->next == nullptr)
    {
        int choice;
        cout << "Only one node to delete, Do you want to delete it?" << endl;
        cin >> choice;
        if (choice == 1)
        {
            delete head;
            cout << "Node deleted successfully" << endl;
            return nullptr;
        }
    }
    else{
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        while(cur!=nullptr&&count<pos-1)
        {
            prv=cur;
            cur=cur->next;
            count++;
        }
        prv->next=cur->next;
        cur->next->prev=prv->next;
        delete cur;
        cout<<"Deleted Successfully"<<endl;
        return head;
    }
}
node *delete_at_data(node *head,int data)
{
    if(head==nullptr)
    {
        cout<<"Empty list"<<endl;
        return head;
    }
    else if (head->next == nullptr)
    {
        int choice;
        cout << "Only one node to delete, Do you want to delete it?" << endl;
        cin >> choice;
        if (choice == 1)
        {
            delete head;
            cout << "Node deleted successfully" << endl;
            return nullptr;
        }
    }
    else{
        node *cur=head;
        node *prv=nullptr;
        while(cur!=nullptr&&cur->data!=data)
        {
            prv=cur;
            cur=cur->next;
        }
        prv->next=cur->next;
        cur->next->prev=prv->next;
        delete cur;
        cout<<"Deleted Successfully"<<endl;
        return head;
    }
}
void display(node *head)
{
    node *cur = head;
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    else
    {
        cout << "Content is:" << endl;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}
int main()
{
    struct node *head = nullptr;
    int data, choice, option, pos;
    while (choice)
    {
        cout << "MENU:" << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Insert after position" << endl;
        cout << "5. Insert before position" << endl;
        cout << "6. Delete at front" << endl;
        cout << "7. Delete at end" << endl;
        cout<<"8. Delete at pos"<<endl;
        cout<<"9. Delete after pos"<<endl;
        cout<<"10. Delete before position"<<endl;
        cout<<"11. Delete based on data"<<endl;
        cout << "12. Display" << endl;
        cout << "Enter your choice" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Enter the data" << endl;
            cin >> data;
            if (option == 1)
            {
                head = insert_at_front(head, data);
            }
            else if (option == 2)
            {
                head = insert_at_end(head, data);
            }
            else if (option == 3)
            {
                cout << "Enter the position" << endl;
                cin >> pos;
                head = insert_at_pos(head, data, pos);
            }
            else if (option == 4)
            {
                cout << "Enter the position" << endl;
                cin >> pos;
                head = insert_after_pos(head, data, pos);
            }
            else if (option == 5)
            {
                cout << "Enter the position" << endl;
                cin >> pos;
                head = insert_before_pos(head, data, pos);
            }
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            if (option == 6)
            {
                head = delete_at_front(head);
            }
            else if (option == 7)
            {
                head = delete_at_end(head);
            }
            else if(option==8)
            {
                cout<<"Enter position"<<endl;
                cin>>pos;
                head=delete_at_pos(head,pos);
            }
            else if(option==9)
            {
                cout<<"Enter position"<<endl;
                cin>>pos;
                head=delete_after_pos(head,pos);
            }
            else if(option==10)
            {
                cout<<"Enter position"<<endl;
                cin>>pos;
                head=delete_before_pos(head,pos);
            }
            else if(option==11)
            {
                cout<<"Enter the data"<<endl;
                cin>>data;
                head=delete_at_data(head,data);
            }
            break;
        case 12:
            display(head);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
        cout << "Do you want to continue?" << endl;
        cin >> choice;
    }
    // Free the allocated memory before exiting the program
    node *cur = head;
    while (cur != nullptr)
    {
        node *temp = cur;
        cur = cur->next;
        delete temp;
    }
    return 0;
}