
// #include<iostream>
// using namespace std;
// using std::string;

// struct node
// {
//     int data;
//     struct node *next;
// };
// node *insert_at_end(struct node *head, int data)
// {
//     struct node *cur;
//     cur=head;
//     struct node *newn=(struct node *)malloc(sizeof(struct node));
//     newn->data=data;
//     newn->next=nullptr;
//     if(head==nullptr)
//     {
//         head=newn;
//     }
//     else
//     {
//         while(cur->next!=nullptr)
//         {
//             cur=cur->next;
//         }
//         cur->next=newn;
//     }
//     return head;
// }
// void display(struct node *head,int n)
// {
//     int i;
//     if(head==nullptr)
//     {
//         cout<<"Empty linked list"<<endl;
//         return;
//     }
//     else
//     {
//         struct node *cur=head;
//         while(cur!=nullptr)
//         {
//             cout<<cur->data<<endl;
//             cur=cur->next;
//         }
//     }
// }
// int main()
// {
//     struct node *head;
//     int i,n,data;
//     cout<<"enter the no. of nodes you want to enter"<<endl;
//     cin>>n;
//     for(i=0;i<n;i++)
//     {
//         cout<<"Enter the data: ";
//         cin>>data;
//         head=insert_at_end(head,data);
//     }
//     display(head,n);
//     return 0;
// }



