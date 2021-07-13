#include<iostream>
using namespace std;


void deletion_heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left <n && arr[left] > arr[largest])
        largest = left;
    if(right <n && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        deletion_heapify(arr, n,largest);
    }
}

void insertion_heapify(int arr[], int n, int i)
{

    int largest = (i-1)/2;
    if(arr[largest]>0)
    {
        if(arr[i]>arr[largest])
        {
            swap(arr[i], arr[largest]);
            insertion_heapify(arr, n, largest);
        }
    }
}
void insertion(int arr[], int& n)
{
    int value;
    cout<<"Enter value : ";
    cin>>value;
    n = n+1;
    arr[n-1] = value;
    insertion_heapify(arr, n, n-1);
}

void deletion(int arr[], int& n)
{
    if(n==0)
    {
        cout<<"Heap is Empty\n";
        return;
    }
    int value = arr[0];
    int last_element = arr[n-1];
    arr[0] = last_element;
    n = n-1;
    cout<<"Deleted Element is " << value <<"\n";
    deletion_heapify(arr, n, 0);
}

void print(int arr[], int n)
{
    if(n==0)
    {
        cout<<"Heap is Empty\n";
        return;
    }
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

void heapsort(int arr[], int& n)
{
    if(n==0)
    {
        cout<<"\n";
        return;
    }
    for(int i=n-1; i>0; i--)
    {
        swap(arr[i], arr[0]);
        deletion_heapify(arr, i, 0);
    }
}
int main()
{
    int arr[100], n = 0;
    while(1)
    {
        int choice;
        cout<<"Press\n 1. insertion\n 2. deletion\n 3. print\n 4. Heap sort\n 5. Exit\n";
        cout<<"Enter Your Choice :: ";
        cin>>choice;
        switch(choice)
        {
        case 1 :
            insertion(arr, n);
            break;
        case 2 :
            deletion(arr, n);
            break;
        case 3 :
            print(arr, n);
            break;
        case 4 :
            heapsort(arr,n);
            break;
        case 5:
            exit(1);
        default  :
            cout<<"Invalid Choice\n";
        }
    }
    return 0;
}
