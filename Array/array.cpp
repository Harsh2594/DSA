/*Define an Array class to implement array data structure*/
#include<iostream>
using namespace std;
#define INVALID_INDEX 1;
#define OVER_FLOW 2;
class Array
{
  private:
    int capacity;
    int lastIndex;
    int *ptr;
  public:
  //Deep copy constructor:
    Array(const Array &ar)
    {
      ptr = new int[ar.capacity];
      for(int i=0;i<=lastIndex;i++)
        ptr[i]=ar.ptr[i];
    }
  //define copy assignment operator:
    Array& operator=(Array& ar)
    {
      if(this!=&ar)
      {
        delete[]ptr;
        capacity = ar.capacity;
        lastIndex = ar.lastIndex;
        ptr = new int[capacity];
        for(int i=0;i<=lastIndex;i++)
          ptr[i]=ar.ptr[i];
      }    
      return *this;
    }

  //constuctor:
    Array(int cap)
    {
      capacity = cap;
      lastIndex = -1;
      ptr = new int[capacity];
    }
  //desstructor:
    ~Array()
    {
      delete []ptr; // free allocated memory
    }
  //function to check array is empty or not:
    bool isEmpty()
    {
      return(lastIndex==-1);
    }
  //write a method to append a new value in array(insert at end):
    void append(int value)
    {
      if(isEmpty)
        ptr[0]=value;
      else if(lastIndex+1==capacity)
      {
        throw OVER_FLOW;
      }
      lastIndex++;
      ptr[lastIndex]=value;
    }  
  //insert a new element at specified index:
    void insert(int index,int value)
    {
      int i;
      if(index<0||index>lastIndex+1)
      {
        throw INVALID_INDEX;
      }
      if(lastIndex+1==capacity)
      {
        cout<<"Overflow!"<<endl;
        return;
      }
      for(i=lastIndex;i>=index;i--)
      {
        ptr[i+1]=ptr[i];
      } 
      ptr[index]=value;
      lastIndex++;  

    }  
  //Edit an element at specified index:
    void edit(int index,int value)
    {
      if(index<0||index>=lastIndex+1)
      {
        throw INVALID_INDEX;
      }
      ptr[index]=value;
    }  
  // Delete an element at specified index:
    void remove(int index)
    {
      int i; 
      if(index<0||index>lastIndex)
      {
        throw INVALID_INDEX;
      }
      for(i=index;i<lastIndex;i++)
        ptr[i]=ptr[i+1];
      lastIndex--;  
    }
  //check Array is full by returning true or false:
    bool isOverflow()
    {
      return (lastIndex+1==capacity);
    }
  //Get element at specified index:
    int getElement(int index)
    {
      if(index<0||index>lastIndex)
        throw INVALID_INDEX;
      return ptr[index];
    }    
  //count number of element in array:
    int countElement()
    {
      return lastIndex+1;
    }  
  //find an element in array if find return index otherwise return -1:
    int findElement(int value)
    {
      for(int i=0;ptr[i];i++)
        if(ptr[i]==value)
          return i;
      return -1;    
      
    }   
};
