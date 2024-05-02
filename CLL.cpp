//check insert after and before position


#include<iostream>
using namespace std;
using std::string;

struct node
{
    int data;
    node *next;
    node *prev;
};
node *insert_at_front(node *head,int data)
{
    node *newn=new node;
    newn->data=data;
    if(head==nullptr)
    {
        head=newn;
        newn->next=head;
        newn->prev=head;
        return head;
    }
    else 
    {
        node *cur=head->prev;
        newn->next=head;
        head->prev=newn;
        cur->next=newn;
        newn->prev=cur;
        head=newn;
        cout<<"Inserted successfully"<<endl;
        return head;
    }
}
node *insert_at_end(node *head,int data)
{
    node *newn=new node;
    newn->data=data;
    if(head==nullptr)
    {
        head=newn;
        newn->next=head;
        newn->prev=head;
        return head;
    }
    else 
    {
        node *cur=head->prev;
        newn->next=head;
        head->prev=newn;
        cur->next=newn;
        newn->prev=cur;
        cout<<"Inserted successfully"<<endl;
        return head;
    }
}
node *insert_at_pos(node *head,int data,int pos)
{
    node *newn=new node;
    newn->data=data;
    if(head==nullptr)
    {
        head=newn;
        newn->next=head;
        newn->prev=head;
        return head;
    }
    else if(pos==1)
    {
        node *cur=head->prev;
        newn->next=head;
        head->prev=newn;
        cur->next=newn;
        newn->prev=cur;
        head=newn;
        cout<<"Inserted successfully"<<endl;
        return head;
    }
    else 
    {
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        do
        {
            prv=cur;
            cur=cur->next;
            count++;
        } while (cur!=head&&count<pos);
        prv->next=newn;
        newn->prev=prv;
        newn->next=cur;
        cur->prev=newn;
        cout<<"Inserted successfully"<<endl;
        return head;   
    }
}
node *insert_after_pos(node *head,int data,int pos)
{
    node *newn=new node;
    newn->data=data;
    if(head==nullptr)
    {
        head=newn;
        newn->next=head;
        newn->prev=head;
        return head;
    }
    else if(pos==1 )    //check
    {
        node *cur=head->prev;
        newn->next=head;
        head->prev=newn;
        cur->next=newn;
        newn->prev=cur;
        head=newn;
        cout<<"Inserted successfully"<<endl;
        return head;
    }
    else 
    {
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        do
        {
            prv=cur;
            cur=cur->next;
            count++;
        } while (cur!=head&&count<pos-1);
        prv->next=newn;
        newn->prev=prv;
        newn->next=cur;
        cur->prev=newn;
        cout<<"Inserted successfully"<<endl;
        return head;   
    }
}
node *insert_before_pos(node *head,int data,int pos)
{
    node *newn=new node;
    newn->data=data;
    if(head==nullptr)
    {
        head=newn;
        newn->next=head;
        newn->prev=head;
        return head;
    }
    else if(pos==2)
    {
        node *cur=head->prev;
        newn->next=head;
        head->prev=newn;
        cur->next=newn;
        newn->prev=cur;
        head=newn;
        cout<<"Inserted successfully"<<endl;
        return head;
    }
    else 
    {
        node *cur=head;
        node *prv=nullptr;
        int count=1;
        do
        {
            prv=cur;
            cur=cur->next;
            count++;
        } while (cur!=head&&count<pos-1);
        prv->next=newn;
        newn->prev=prv;
        newn->next=cur;
        cur->prev=newn;
        cout<<"Inserted successfully"<<endl;
        return head;   
    }
}
void display(node *head)
{
    node *cur=head;
    cout<<"Content: "<<endl;
    do
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    } while (cur!=head);
    cout<<endl;
}
int main()
{
    node *head=nullptr;
    int data,pos,choice=1,option;
    while(choice)
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
            cout<<"Enter the data"<<endl;
            cin>>data;
            if(option==1)
            {
                head=insert_at_front(head,data);
            }
            else if(option==2)
            {
                head=insert_at_end(head,data);
            }
            else if(option==3)
            {
                cout<<"Enter position"<<endl;
                cin>>pos;
                head=insert_at_pos(head,data,pos);
            }
            else if(option==4)
            {
                cout<<"Enter position"<<endl;
                cin>>pos;
                head=insert_before_pos(head,data,pos);
            }
            break;
        case 12:
            display(head);
            break;
        default:
            break;
        }
        cout << "Do you want to continue? (1: Yes, 0: No): ";
        cin >> choice;

    }
    cout<<"Exited"<<endl;
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