#include<iostream>
using namespace std;
#define Empty_Stack 1;
#define OVER_FLOW 2;

/*Implement Stack using Array*/

class Stack
{
  private:
    int capacity;
    int top;
    int *ptr;
  public:
    //Constructor:
    Stack(int cap)  
    {
      capacity=cap;
      top = -1;
      ptr = new int[capacity];
    }
    //Destructor:
    ~Stack()
    {
      delete [] ptr;
    }
    //Write a function to stack overflow:
    bool isOverflow()
    {
      return(top+1==capacity);
    }
    //function to check array is empty or not:
    bool isEmpty()
    {
      return(top==-1);
    }
    //function to push element in stack:
    void push(int item)
    {
      if(isEmpty())
      {
        ptr[0]=item;
      }
      else if (top+1==capacity)
      {
        throw OVER_FLOW;
      }
      top++;
      ptr[top]=item;
    }
    //function to show top element in stack:
    void peek()
    {
      if(isEmpty()){throw Empty_Stack;}
      cout<<"Top element in stack = "<<ptr[top]<<endl;
    }
    //function to pop(delete top element) in stack:
    void pop()
    {
      if(isEmpty()){throw Empty_Stack;}
      cout << "Popped element: " << ptr[top] << endl;
      top--; 
    }
   //define a method to reverse a Stack:
   void reverse_stack()
   {
    int left = 0;
    int right = top;
    while(left<right)
    {
      int t=ptr[right];
      ptr[right]=ptr[left];
      ptr[left]=t;
      left++;
      right--;
    }
   }
   //define a method to keep track of minimum value element in stack:
   int track_minimum()
   {
    if(isEmpty()){throw Empty_Stack;}
    int i,min=ptr[0];
    for(i=0;i<=top;i++)
    {
      if(ptr[i]<=min)
        min=ptr[i];
    }
    return min;
   }
  //display stack item:
    void Display_stack()
    {
      for(int i=0;i<=top;i++)
        cout<<ptr[i]<<" ";
      cout<<endl;  
    } 
};

int main()
{
  Stack s(10);
  s.push(3);
  s.push(6);
  s.push(2);
  s.push(1);
  s.push(12);
  s.push(13);
  s.push(99);
  s.peek();
  s.Display_stack();
  s.pop();
  s.peek();
  s.reverse_stack();
  s.Display_stack();
  cout<<s.track_minimum();
}