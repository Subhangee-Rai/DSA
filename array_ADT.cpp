#include<iostream>
using namespace std;
using std::string;

class custom_array
{
    public:
    int total_size, used_size;
    custom_array()
    {
        total_size=100; used_size=10;
    }
    custom_array(int tsize, int usize)
    {
        total_size=tsize; used_size=usize;
    }
    void display(string arr[],int entry)
    {
        int i,flag=0;
        cout<<"Details are: "<<endl;
        for(i=0;i<used_size;i++)
        {
            cout<<arr[i]<<" ";
            if(i==flag+(entry-1))
            {
                cout<<endl;
                flag+=3;
            }
        }
        cout<<endl;
    }
    void create(string arr[])
    {
        int i, flag=0;
        cout<<"Enter student name, roll no, marks"<<endl;
        for(i=0;i<used_size;i++)
        {
            cin>>arr[i];
        }
        cout<<endl;
    }
};
int main()
{
    // for one entry 
    // custom_array obj1(10,3);
    // string arr[]={"Max","80","2"};
    // obj1.display(arr);


    /*creating and displaying an array consisting of students name, roll & marks with the help of class*/
    int i;
    custom_array obj(100,9);
    string arr[100];
    obj.create(arr);
    obj.display(arr,3);
    return 0;
}