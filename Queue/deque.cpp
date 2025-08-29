#include<iostream>
using namespace std;
#define Deque_Underflow 1;
/*Define a class Deque with node type pointers front and rear as member variables
Implement queue using doubly linked list.*/
struct Node
{
  int item;
  Node *next;
  Node *prev;
};
class Deque
{
  private:
    Node *front;
    Node *rear;
  public:
    Deque()
    {
      front = nullptr;
      rear = nullptr;
    }
    ~Deque()
    {
      while(front!=nullptr)
      {
        delete_front();
      }
      
    }
    void insert_front(int);
    void insert_rear(int);
    void delete_front();
    void delete_rear();
    int get_front();
    int get_rear();
    bool isEmpty();
    
};

bool Deque::isEmpty()
{
  return(rear==nullptr&&front==nullptr);
}

void Deque::insert_rear(int data)
{
  Node *n = new Node;
  n->item=data;
  n->next = nullptr;
  n->prev = nullptr;
  //Case-1: Empty deque:
  if(isEmpty())
  {
    rear = front = n;
  }
  //Case-2:At least One Node:
  else
  {
    rear->next = n;
    n->prev=rear;
    rear = n;
  }
}
void Deque::insert_front(int data)
{
  Node *n = new Node;
  n->item=data;
  n->next = nullptr;
  n->prev = nullptr;
  //Case-1: Empty deque:
  if(isEmpty())
  {
    rear = front = n;
  }
  //Case-2: At least one node:
  else
  {
    front->prev=n;
    n->next=front;
    front =n;
  }
}
void Deque::delete_front()
{
  //Case-1 Empty deque:
  if(isEmpty())
  {
    throw Deque_Underflow;
  }
  //Case-2 Only One Node:
  else if(front==rear)
  {
    delete front;
    front=rear=nullptr;
  }
  else{
    Node *t = front;
    front->next->prev = nullptr;
    front = front->next;
    delete t;
  }
  
}
void Deque::delete_rear()
{
  //Case-1 Empty deque:
  if(isEmpty())
  {
    throw Deque_Underflow;
  }
  //Case-2 Only One Node:
  else if(front==rear)
  {
    delete rear;
    front=rear=nullptr;
  }
  else{
    Node *t = rear;
    rear->prev->next = nullptr;
    rear = rear->prev;
    delete t;
  }
  
}

int Deque::get_front()
{
  //Case-1 Empty deque:
  if(isEmpty())
  {
    throw Deque_Underflow;
  }
  else
  {
    return front->item;
  }
}

int Deque::get_rear()
{
  //Case-1 Empty deque:
  if(isEmpty())
  {
    throw Deque_Underflow;
  }
  else
  {
    return rear->item;
  }
}