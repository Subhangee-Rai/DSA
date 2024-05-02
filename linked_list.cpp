// SLL

//write for searching and deleting a node and adding it to the end

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *insert_at_front(node *head, int data)
{
    node *newn = new node;
    newn->data = data;
    newn->next = head;
    head = newn;
    return head;
}

node *insert_at_end(node *head, int data)
{
    node *cur = head;
    node *newn = new node;
    newn->data = data;
    newn->next = nullptr;

    if (head == nullptr)
    {
        head = newn;
    }
    else
    {
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newn;
    }
    return head;
}

node *insert_at_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->next = nullptr;

    if (pos == 1)
    {
        newn->next = head;
        head = newn;
    }
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;

        while (cur != nullptr && count < pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }

        prev->next = newn;
        newn->next = cur;
    }

    return head;
}
node *insert_before_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->next = nullptr;

    if (pos == 1)
    {
        newn->next = head;
        head = newn;
    }
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;

        while (cur != nullptr && count <= pos - 1)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }

        prev->next = newn;
        newn->next = cur;
    }

    return head;
}
node *insert_after_pos(node *head, int data, int pos)
{
    node *newn = new node;
    newn->data = data;
    newn->next = nullptr;

    if (pos == 0)
    {
        newn->next = head;
        head = newn;
    }
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;

        while (cur != nullptr && count <= pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }

        prev->next = newn;
        newn->next = cur;
    }

    return head;
}

node *delete_at_end(node *head)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
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
        node *prev = nullptr;
        while (cur->next != nullptr)
        {
            prev = cur;
            cur = cur->next;
        }
        delete cur;
        prev->next = nullptr;
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
node *delete_at_front(node *head)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
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
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
node *delete_at_pos(node *head, int pos)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
    }
    else if (head->next == nullptr && pos == 1)
    {
        delete head;
        cout << "Node deleted successfully" << endl;
        return nullptr;
    }
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;
        while (cur->next != nullptr && count < pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next = cur->next;
        delete cur;
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
node *delete_before_pos(node *head, int pos)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
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
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;
        while (cur->next != nullptr && count < pos - 1)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next = cur->next;
        delete cur;
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
node *delete_after_pos(node *head, int pos)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
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
    else
    {
        node *cur = head;
        node *prev = nullptr;
        int count = 1;
        while (cur->next != nullptr && count < pos + 1)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next = cur->next;
        delete cur;
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
node *delete_at_data(node *head, int data)
{
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return nullptr;
    }
    else if (head->next == nullptr && head->data == data)
    {
        delete head;
        cout << "Node deleted successfully" << endl;
        return nullptr;
    }
    else
    {
        node *cur = head;
        node *prev = nullptr;
        while (cur->next != nullptr && cur->data!=data)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        cout << "Node deleted successfully" << endl;
        return head;
    }
}
void display(node *head)
{
    cout << "Data in the linked list is:" << endl;
    if (head == nullptr)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    else
    {
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << "  ";
            cur = cur->next;
        }
        cout << endl;
    }
}

int main()
{
    node *head = nullptr;
    int data, pos, ch, option;

    while (ch)
    {
        cout << "MENU" << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Insert before position" << endl;
        cout << "5. Insert after position" << endl;
        cout << "6. Delete at end" << endl;
        cout << "7. Delete at front" << endl;
        cout << "8. Delete at position" << endl;
        cout << "9. Delete before position" << endl;
        cout << "10. Delete after position" << endl;
        cout<<"11. Delete the data"<<endl;
        cout << "12. Display the content" << endl;
        cout << "Choose one option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Enter the data: ";
            cin >> data;

            if (option == 1)
                head = insert_at_front(head, data);
            else if (option == 2)
                head = insert_at_end(head, data);
            else if (option == 3)
            {
                cout << "Enter position where you want to enter data: ";
                cin >> pos;
                head = insert_at_pos(head, data, pos);
            }
            else if (option == 4)
            {
                cout << "Enter the position: ";
                cin >> pos;
                head = insert_before_pos(head, data, pos);
            }
            else if (option == 5)
            {
                cout << "Enter the position: ";
                cin >> pos;
                head = insert_after_pos(head, data, pos);
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
                head = delete_at_end(head);
            }
            else if (option == 7)
            {
                head = delete_at_front(head);
            }
            else if (option == 8)
            {
                int pos;
                cout << "Enter the position" << endl;
                cin >> pos;
                head = delete_at_pos(head, pos);
            }
            else if (option == 9)
            {
                int pos;
                cout << "Enter the position" << endl;
                cin >> pos;
                head = delete_before_pos(head, pos);
            }
            else if (option == 10)
            {
                int pos;
                cout << "Enter the position" << endl;
                cin >> pos;
                head = delete_after_pos(head, pos);
            }
            else if(option==11)
            {
                int data;
                cout<<"Enter data of node to be deleted"<<endl;
                cin>>data;
                head=delete_at_data(head,data);
            }
            break;
        case 12:
            display(head);
            break;

        default:
            cout << "Invalid option" << endl;
        }

        cout << "Do you want to continue? (1: Yes, 0: No): ";
        cin >> ch;
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
