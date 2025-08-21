#include<iostream>
using namespace std;

/*define a function to implement selection sort*/
void selection_sort(int a[],int size)
{
  int i,j,min_index;
  for(j=0;j<size-1;j++)
  {
    min_index=j;
    for(i=j+1;i<size;i++)
    {
      if(a[i]<a[min_index])
        min_index=i;
    } 
    if(j!=min_index){
      int temp = a[j];   //swap min value with first index of 1st loop: 
      a[j]=a[min_index];
      a[min_index]=temp;  
    }  
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
  selection_sort(a,size);
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
  return 0;  
}   