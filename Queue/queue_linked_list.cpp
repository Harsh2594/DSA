#include<iostream>
using namespace std;
#define Queue_Underflow 1

/*Implement Queue using linked list*/
struct Node
{
  int item;
  Node *next;
};

class Queue
{
  private:
    Node *front;
    Node *rear;
  public:
    Queue()
    {
      front=nullptr;
      rear=nullptr;
    }
    ~Queue()
    {
      while(front!=nullptr)
      {
        Node *t = front;
        front=front->next;
        delete t;
      }
      rear=nullptr;
    }
    void insert_rear(int);
    bool isEmpty(){ return front==nullptr&&rear==nullptr;}

    int getfront()
    {
      if(isEmpty())
      {
        throw Queue_Underflow;
      }
      return front->item;
    }

    int get_rear()
    {
      if(isEmpty())
      {
        throw Queue_Underflow;
      }
      return rear->item;
    }
    void delete_front();
    void delete_rear();
    int count_element();
};

void Queue::insert_rear(int data)
{
  Node *n = new Node;
  n->item=data;
  n->next=nullptr;
  //Empty queue:
  if(isEmpty())
  {
    rear=n;
    front=n;
  }
  //At least One Node:
  else
  {
    rear->next=n;
    rear = n;
  }
}

void Queue::delete_front()
{
  if(isEmpty())
  {
    throw Queue_Underflow;
  }
  else
  {
    Node *t = front;
    front=front->next;
    delete t;
  }
  if(front==nullptr)
    rear =nullptr;
}

void Queue::delete_rear()
{
  //Case-1: Empty list:
  if(isEmpty())
  {
    throw Queue_Underflow;
  }
  //Case-2: Only one node:
  else if(front==rear)
  {
    delete rear;
    front=rear=nullptr;
  }
  //Case-3: More than one Node:
  else
  {
    Node *currt = front;
    while(currt->next->next!=nullptr)
    {
      currt=currt->next;
    }
    delete rear;
    rear=currt;
    rear->next=nullptr;
  }
}

int Queue::count_element()
{
  int count=0;
  if(isEmpty())
  {
    throw Queue_Underflow;
  }
  Node *currt = front;
  while(currt!=nullptr)
  {
    count++;
    currt=currt->next;
  }
  return count;
}

int main()
{
  Queue q;
  q.insert_rear(10);
  q.insert_rear(20);
  q.insert_rear(30);
  q.insert_rear(40);
  q.insert_rear(50);
  cout<<q.get_rear()<<endl;
  cout<<q.getfront()<<endl;
  cout<<q.count_element();
    
}