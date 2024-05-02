#include<iostream>
using namespace std;
using std::string;

struct stack
{
    stack *next;
    char data;
};
stack *push(stack *head,char data)
{
    stack *cur=head;
    stack *newn=new stack;
    newn->next=nullptr;newn->data=data;
    if(head==nullptr)
    {
        return newn;
    }
    else
    {
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=newn;
        return head;
    }
}
stack *pop(stack *head)
{
    stack *cur=head;
    head=head->next;
    delete cur;
    return head;
}
void check(stack *head,string exp)
{
    int i;
    for(i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
        {
            head=push(head,exp[i]);
        }
        if(exp[i]==')')
        {
            if(head==nullptr)
            {
                cout<<"Unabalanced"<<endl;
                return;
            }
            head=pop(head);
        }
        if(exp[i]=='[')
        {
            head=push(head,exp[i]);
        }
        if(exp[i]==']')
        {
            if(head==nullptr)
            {
                cout<<"Unabalanced"<<endl;
                return;
            }
            head=pop(head);
        }
        if(exp[i]=='{')
        {
            head=push(head,exp[i]);
        }
        if(exp[i]=='}')
        {
            if(head==nullptr)
            {
                cout<<"Unabalanced"<<endl;
                return;
            }
            head=pop(head);
        }
    }
    if(head==nullptr)
    {
        cout<<"Balanced"<<endl;
        return;
    }
    else
    {
        cout<<"unbalanced"<<endl;
        return;
    }
}
int main()
{
    stack *head=nullptr;
    string exp="(2+3)-[3*4]{5*6}";
    check(head,exp);
    return 0;
}