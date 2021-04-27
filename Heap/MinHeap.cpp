#include<iostream>
using namespace std;

const int capacity = 10;
int length = 0;
int items[capacity];

int getParentIndex(int childIndex){ return (childIndex - 1) / 2; }
int getLeftChildIndex(int index){ return 2 * index + 1; }
int getRightChildIndex(int index){ return 2 * index + 2; }

bool hasParent(int childIndex){ return getParentIndex(childIndex) >= 0; }
bool hasLeftChild(int index){ return getLeftChildIndex(index) < length; }
bool hasRightChild(int index){ return getRightChildIndex(index) < length; }

int getParent(int childIndex){ return items[getParentIndex(childIndex)]; }
int getLeftChild(int index){ return items[getLeftChildIndex(index)]; }
int getRightChild(int index){ return items[getRightChildIndex(index)]; }

bool isEmpty(){ return length == 0; };

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void heapifyDown()
{
    int index = 0;
    while(hasLeftChild(index))
    {
        int smallestChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && getLeftChild(index) > getRightChild(index))
        {
            smallestChildIndex = getRightChildIndex(index);
        }

        if(items[index] < items[smallestChildIndex])
        {
            break;
        }
        else
        {
            swap(&items[index], &items[smallestChildIndex]);
        }

        index = smallestChildIndex;
    }
}

void heapifyUp()
{
    int index  = length - 1;
    while(hasParent(index) && items[index] < getParent(index))
    {
        swap(&items[index], &items[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

int top()
{
    if(isEmpty())
    {
        return -1;
    }

    return items[0];
}

int pop()
{
    if(isEmpty())
    {
        return -1;
    }

    int root = items[0];
    items[0] = items[length - 1];
    length--;
    heapifyDown();

    return root;
}

void insert(int item)
{
    if(length > capacity)
    {
        // Need to double the capacity
        return;
    }

    items[length] = item;
    length++;
    heapifyUp();
}

int main()
{
    int n = 7;
    int arr[] = {4, 8, 2 , 3, 5, 7, 1};

    for(int i = 0; i < n; i++)
    {
        insert(arr[i]);
    }

    cout<<"Top item = "<<top()<<endl;
    cout<<"Printing items: \n";
    for(int i = 0; i < n; i++)
    {
        cout<<items[i]<<" ";
    }
    cout<<endl;
}