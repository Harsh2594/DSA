#include<iostream>
using namespace std;
/*Define a logic to implement priority queue using 2D array:*/
class Priority_Queue
{
  private:
    int capacity;
    int size;
    int (*ptr)[2];
  public:
    Priority_Queue(int cap)
    {
      capacity=cap;
      size = 0;
      ptr=new int[capacity][2];
    }
    ~Priority_Queue()
    {
      delete []ptr;
    }
    // insert element with priority
    void insert(int data,int pno)
    {
      if(size==capacity){
        cout<<"Queue is full"<<endl;
        return;
      }  
      ptr[size][0]=data;
      ptr[size][1]=pno;
      size++;
    }
    void delete_high_pno()
    {
      if(size==0){
        cout<<"Queue is Empty"<<endl;
        return;
      }  
      int maxIndex=0;
      for(int i=1;i<size;i++)
      {
        if(ptr[i][1]>ptr[maxIndex][1])
          maxIndex = i;
      }
      cout<<"Deleted Element = "<<ptr[maxIndex][0]<<endl<<"Priority = "<<ptr[maxIndex][1]<<endl;

      for(int i=maxIndex;i<size;i++)
      {
        ptr[i][0]=ptr[i+1][0];
        ptr[i][1]=ptr[i+1][0];
      }
      size--;
    }
    void display()
    {
      if(size==0){
        cout<<"Queue is Empty"<<endl;
        return;
      }
      cout<<"Queue Element"<<endl;
      for(int i=0;i<size;i++)
      {
        cout<<"Data = "<<ptr[i][0]<<endl<<"Priority = "<<ptr[i][1]<<endl;
      }
    }

};
