#include<iostream>
using namespace std;
#define Queue_Overflow 1;
#define Queue_Underflow 2;
/*Write a Queue Data structure using Array*/
class Queue
{
  private:
    int capacity;
    int front;
    int rear;
    int *ptr;
  public:
    Queue(int cap)
    {
      capacity=cap;
      front = -1;
      rear=-1;
      ptr = new int[capacity];
    }  
    ~Queue(){delete [] ptr;}
    void insert(int);
    void view_rear();
    void view_front();
    void delete_front();
    bool isEmpty(){return (front==-1);}
    bool isFull(){return (front+1==capacity);}
    void count_element();
    void display();
};

void Queue::insert(int data)
{
  //Case-1: full Queue
  if(rear+1==capacity)
  {
    throw Queue_Overflow;
  }  
  //Case-2: Empty Queue
  if(front==-1&&rear==-1)
  {
   front=rear=0;
   ptr[rear]=data;
  }
  //Case-3: At least One element  
  else if(front==0&&rear<capacity-1)
  {
   rear++;
   ptr[rear]=data;
  }

}
void Queue::view_rear()
{
  cout<<"rear element = "<<ptr[rear]<<endl;
}
void Queue::view_front()
{
  cout<<"front element = "<<ptr[front]<<endl;
}
void Queue::delete_front()
{
  //Empty queue:
  if(front==-1)
  {
    throw Queue_Underflow;
  }
  else
  {
    front++;
  }
}

void Queue::count_element()
{
  if(isEmpty())
  {
    throw Queue_Underflow;
  }
  else
  {
  int count = rear-front+1;
  cout << "Number of elements in queue: " << count << endl;
  }
} 

void Queue::display()
{
  for(int i=front;i<=rear;i++)
    cout<<ptr[i]<<" ";
}
int main()
{
  Queue q(10);
  q.insert(10);
  q.insert(20);
  q.insert(30);
  q.insert(40);
  q.insert(50);
  q.view_front();
  q.view_rear();
  q.delete_front();
  q.view_front();
  q.count_element();
  q.display();
}