#include<iostream>
using namespace std;

/*Write a function to implement quick_sort using recursion*/
int quick(int a[],int left,int right)
{
  int loc=left,t;

  while(left<right)
  {
    while(a[loc]<a[right]&&left<right)
    {
      right--;
    }
    if(left==right)
      break;
    t=a[loc];
    a[loc]=a[right];
    a[right]=t;
    loc = right;

    while(a[loc]>a[left]&&left<right)
      left++;
    if(left==right)
      break;  
    t=a[loc];
    a[loc]=a[left];
    a[left]=t;  
    loc = left;
  }
  return loc;
}

void quick_sort(int a[],int l,int u)
{
  int loc = quick(a,l,u);
  if(loc>l+1)
    quick_sort(a,l,loc-1);//left half
  if(loc<u-1)
    quick_sort(a,loc+1,u);//right half
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
  quick_sort(a,0,size-1);
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
  return 0;  
}  
