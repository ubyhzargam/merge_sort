#include<iostream>
using namespace std;

void Merge(int A[],int l,int mid, int h)
{
    int i,j,k=l;
    i=l;
    j=mid+1;
    int B[100];
    while(i<=mid&&j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(int i=l;i<=h;i++)
        A[i]=B[i];
}

void IterativeMSort(int A[],int n)
{
    int l,h,mid,p;
    for(p=2;p<=n;p=p*2)
    {
        for(int j=0;j+p-1<n;j=j+p)
        {
            l=j;
            h=j+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,(p/2)-1,n-1);
}

void RecursiveMSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=((l+h)/2);
        RecursiveMSort(A,0,mid);
        RecursiveMSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void Display(int A[],int n)
{
    cout<<"The sorted elements are given by : "<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}

int main()
{
    cout<<"Enter the number of elements to be entered in the Array : "<<endl;
    int n;
    cin>>n;
    int A[100];
    cout<<"Enter the elements in the array which are to be sorted "<<endl;
    for(int i=0;i<n;i++)
    cin>>A[i];
    IterativeMSort(A,n);
    Display(A,n);
    cout<<"Enter the number of elements of 2nd array to be sorted using Recursive Method :"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    RecursiveMSort(A, 0, n-1);
    Display(A,n);
    return 0;
}
