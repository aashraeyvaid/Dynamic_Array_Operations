#include<iostream>
using namespace std;

class array
{
    private:
    int *arr;
    int size;
    int top=0;

    public:
    
    array(int size=1);
    ~array();
    int& operator[](int index);
    int length();
    int Size();
    int search(int value);
    void append(int element);
    void insert(int index,int value);
    void size_inc(int n);
    void display();
    void del(int x);
    void reverse();
    void sort();
    void segregate();
    bool sort_check();
    array operator+(array arr2);
};

int& array:: operator[](int index)
{
    return arr[index];
}

array:: array(int size)
{
    this-> size=size;
    arr=new int[size];
}

array::~array()
{
    delete []arr;
}

void array:: append(int element)
{
    if(top==size)
    size_inc(size+1);
    arr[top]=element;
    top++;
}

void array::insert(int index,int value)
{
    if(top==size)
    size_inc(size+1);
    for(int i=top;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=value;
    top++;
}

void array::size_inc(int n)
{
    int *na;
    na=new int[n];
    for(int i=0;i<size;i++)
    {
        na[i]=arr[i];
    }
    size=n;
    delete []arr;
    arr=na;
    na=nullptr;
}

void array::display()
{
    for(int i=0;i<top;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int array::length()
{
    return top;
}

int array::Size()
{
    return size;
}

void array::del(int x)
{
    int i=0;
    for(i;arr[i]!=x;i++)
    {}
    if(i!=top)
    {
        for(i;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        top--;
        int *a=new int[size-1];
        for(int i=0;i<top;i++)
        {
            a[i]=arr[i];
        }
        delete []arr;
        arr=a;
        a=nullptr;
    }
    else
    {
        cout<<"Element not found!!"<<endl;
    }
}

void array::reverse()
{
    for(int i=top-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void array::sort()
{
    for(int i=0;i<top-1;i++)
    {
        for(int j=i+1;j<top;j++)
        {
            if(arr[i]>arr[j])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
    }
}

int array::search(int value)
{
    if(sort_check()==true && top%2!=0)
    {
        int b=0,e=top-1,mid;
        while(b<=e)
        {
            mid=(b+e)/2;
            if(arr[mid]==value)
            return mid;
            else if(value>arr[mid])
            b=mid+1;
            else
            e=mid-1;
        }
        return -1;
    }
    else
    {
        for(int i=0;i<top;i++)
        {
            if(arr[i]==value)
            return i;
        }
        return -1;
    }
}

bool array::sort_check()
{
    for(int i=0;i<top-1;i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}

void array::segregate()
{
    int i=0,j=top-1;
    while(i<j)
    {
        while(arr[i]<0)
        {
            i++;
        }
        while(arr[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            arr[i]=arr[i]+arr[j];
            arr[j]=arr[i]-arr[j];
            arr[i]=arr[i]-arr[j];
        }
    }
}

array array::operator+(array arr2)
{
    sort();
    arr2.sort();
    array combined(size+arr2.size);
    int i=0,j=0,k=0;
    while(i<top && j<arr2.top)
    {
        if(arr[i]<arr2[j])
        {
        combined.append(arr[i++]);
        }
        else
        {
        combined.append(arr2[j++]);
        }
    }
    for(;i<top;i++)
    {
        combined.append(arr[i]);
    }
    for(;j<arr2.top;j++)
    {
        combined.append(arr2[j]);
    }
    return combined;
}

int main()
{
    array a1(4);
    a1.append(23);
    a1.append(12);
    a1.display();
    a1.insert(1,47);
    a1.display();
    a1.append(28);
    a1.display();
    a1.append(33);
    a1.display();
    a1.insert(4,30);
    a1.display();
    cout<<a1.length()<<endl;
    cout<<a1.Size()<<endl;
    a1.size_inc(10);
    cout<<a1.length()<<endl;
    cout<<a1.Size()<<endl;
    a1.append(19);
    a1.display();
    cout<<a1.search(30)<<endl;
    a1.sort();
    a1.display();
    a1.append(-1);
    a1.display();
    a1.insert(3,-7);
    a1.display();
    a1.insert(5,-13);
    a1.display();
    a1.segregate();
    a1.display();
    a1.reverse();
    a1.display();
    a1.del(23);
    a1.display();
    a1.sort();
    a1.display();

    cout<<endl<<endl;

    array a2(5);
    a2.append(3);
    a2.append(1);
    a2.append(4);
    a2.append(2);
    a2.append(5);
    a2.display();
    a2.sort();
    a2.display();

    cout<<endl<<endl;
    
    array a3=a1+a2;
    a3.display();
}