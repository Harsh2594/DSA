#include<iostream>
using namespace std;

//Bubble_sort algoritham:
void Bubble_sort(int a[],int size)
{
  int i,r;
  for(r=1;r<size;r++)
    for(i=0;i<=size-1-r;i++)
      if(a[i]>a[i+1])
      {
        int t = a[i];
        a[i] = a[i+1];
        a[i+1]=t;
      }
}

//Modified bubble-sort:
void mod_Bubble_sort(int a[],int size)
{
  int i,r,isSwap;
  for(r=1;r<size;r++)
  {
    for(i=0;i<=size-1-r;i++)
    {
      isSwap=0;
      if(a[i]>a[i+1])
      {
        int t = a[i];
        a[i] = a[i+1];
        a[i+1]=t;
        isSwap=1;
      }
    }  
    if(!isSwap)
      break;  
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
  mod_Bubble_sort(a,size);
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
  return 0;  

}