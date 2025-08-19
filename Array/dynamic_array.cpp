#include<iostream>
using namespace std;
#define INVALID_INDEX 1;
#define OVER_FLOW 2;
#define Element_Not_found 3;

/*Define a dynamic array data structure*/

class DynArray
{
  private:
    int capacity;
    int last_index;
    int *ptr;
  protected:
    void doubleArray();
    void halfArray();  
  public:
    DynArray(int cap)
    {
      capacity=cap;
      last_index =-1;
      ptr = new int[capacity];
    }  
    int current_capacity();
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int,int);
    void remove(int);
   
    int getElement(int);
    int count_element();
    ~DynArray(){ delete []ptr;}
    int find_element(int);
};
void DynArray::doubleArray()
{
  int *temp;
  temp = new int[2*capacity];      
  for(int i=0;i<=last_index;i++)//copy data
    temp[i]=ptr[i];  
  delete []ptr; //delete old memory
  ptr = temp;
  capacity *=2;  
}
void DynArray::halfArray()
{
  int *temp;
  temp = new int[capacity/2];      
  for(int i=0;i<=last_index;i++)//copy data
    temp[i]=ptr[i];  
  delete []ptr; //delete old memory
  ptr = temp;
  capacity = capacity/2;
}
int DynArray::current_capacity()
{
  return capacity;
}
bool DynArray::isEmpty()
{
  return (last_index==-1);
}
void DynArray::append(int value)
{
  if(last_index+1==capacity)
    this->doubleArray(); 
  last_index++;
  ptr[last_index]=value;  
}
void DynArray::insert(int index,int value)
{
  if(index<0||index>last_index+1)
    throw INVALID_INDEX;
  if(last_index+1==capacity)
  {
    this->doubleArray();
  }
  for(int i=last_index;i>=index;i--)
  {
    ptr[i+1]=ptr[i];
  } 
  ptr[index]=value;
  last_index++;  
}
// Delete an element at specified index:
void DynArray::remove(int index)
{
  int i; 
  if(index<0||index>last_index)
  {
    throw INVALID_INDEX;
  }
  for(i=index;i<last_index;i++)
    ptr[i]=ptr[i+1];
  last_index--;  
  if(last_index<capacity/2-1)
    this->halfArray();
}
bool DynArray::isFull()
{
  return(last_index+1==capacity);
}
//Get element at specified index:
int DynArray::getElement(int index)
{
  if(index<0||index>last_index)
    throw INVALID_INDEX;
  return ptr[index];      
}  
 //count number of element in array:
int DynArray::count_element()
{
  return last_index+1;
} 
//find an element in array if find return index otherwise return -1:
int DynArray::find_element(int value)
{
  for(int i=0;ptr[i];i++)
    if(ptr[i]==value)
      return i;
  return -1;   
      
}  

int main()
{
  DynArray drr(5);
  drr.append(2);
  drr.append(4);
  drr.append(1);
  drr.append(5);
  drr.append(11);
  drr.append(12);
  drr.insert(3,15);
  cout<<"index of 12 "<<drr.find_element(12)<<endl;
  cout << "Current capacity: " << drr.current_capacity() << endl;
  cout << "Total elements: " << drr.count_element() << endl;
}