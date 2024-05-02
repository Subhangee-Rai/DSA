// here code for insertion, deletion, searching & sorting in array is written here

#include <iostream>
using namespace std;
using std::string;

void display(int arr[100], int n)
{
    int i;
    cout << "Array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// INSERTION
void insert_at_index(int arr[100], int n, int capacity, int data, int index)
{
    int i, temp;
    if (index >= capacity)
    {
        cout << "Limit of the array is reached" << endl;
        return ;
    }
    for (i = n - 1; i >= index; i--) // here we are raversing the array backwards and shifting all elements one index formard till the index at which we want to insert is free
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = data;
    cout << "Inserted successfully" << endl;
}

// DELETION 
void delete_at_index(int arr[100], int n, int capacity, int index)
{
    int i, temp;
    if (index >= capacity)
    {
        cout << "Limit of the array is reached" << endl;
    }
    for (i = index; i < n; i++) 
    {
        arr[i] = arr[i+1];  //here we are shifting elements backwards from there position so that the element at index is replaced by preceeded element 
    }
    cout << "Deleted successfully" << endl;
}

//SEARCHING - LINEAR
void linear_search(int arr[100],int n,int element)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            cout<<"Element is found at position "<<i+1<<endl;
            return ;
        }
    }
    cout<<"Element is not found!"<<endl;
}

// SEARCHING - BINARY
void binary_search(int arr[100],int n,int element)
{
    int i;
    int high=n-1, low=0;
    int mid,flag=0;
    while(low<=high)
    {
        mid = (high+low)/2;
        if(arr[mid] == element)
        {
            cout<<"Found at index "<<mid<<endl;
            return;
        }
        if(arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
        flag=1;
    }
    cout<<"Not found! "<<endl;
}

int main()
{
    int arr[100] = {1, 2, 4, 3, 6}; // 100 is the total size of the array & n is the size currently used
    int n = 5, element, index;
    display(arr, n);
    cout << "Enter the element to be inserted in the array: " << endl;
    cin >> element;
    cout << "Enter index: ";
    cin >> index;
    insert_at_index(arr, n, 100, element, index);
    n++;    //since after insertion the size of array increases. 
    display(arr, n);
    cout<<"Enter the index to delete element from: "<<endl;
    cin>>index;
    delete_at_index(arr,n,100,index);
    n--;    //after deletion the size of array decreases 
    display(arr,n);
    linear_search(arr,n,0);
    linear_search(arr,n,6);
    binary_search(arr,n,4);
    binary_search(arr,n,11);
    return 0;
}