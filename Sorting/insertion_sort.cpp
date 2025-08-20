#include<iostream>
using namespace std;

/*Define a function to implement insertion sort*/
void insertion_sort(int a[],int size)
{
  int key,i,j;
  for(i=0;i<size;i++)
  {
    key = a[i];
    j=i-1;
    while(j>=0&&a[j]>key)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }
}

int main()
{
  int size;
  cout<<"Enter size of an array: "<<endl;
  cin>>size;
  int a[size];
  cout<<"Enter value in array"<<endl;
  for(int i=0;i<size;i++)
    cin>>a[i];
  insertion_sort(a,5);
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
  return 0;  
}    