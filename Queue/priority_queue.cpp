#include <iostream>
using namespace std;
#define Underflow 1;

/*Define a class PriorityQueue with node type pointer start as member variable
Implement PriorityQueue using singly linked list.*/
struct Node
{
  int item;
  int pno;
  Node *next;
};

class PriorityQueue
{
  private:
    Node *start;
  public:
    PriorityQueue()
    {
      start = nullptr;
    }  
    ~PriorityQueue()
    {
      Node *currt=start;
      while(currt!=nullptr)
      {
        Node *temp = currt;
        currt=currt->next;
        delete temp;
      }
      start = nullptr;
    }
    
    void insert_new(int,int);
    void delete_high_pno();
    int get_high_pno_ele();
    int get_hight_pno();
    bool isEmpty();
};

bool PriorityQueue::isEmpty()
{
  return start==nullptr;
}

void PriorityQueue::insert_new(int data,int pno)
{
  Node *n = new Node;
  n->item=data;
  n->pno=pno;
  n->next=nullptr;
  //Case-1: If Queue is empty:
  if(isEmpty()||pno>start->pno)
  {
    n->next=start;
    start = n;
  }
  //At least one node
  else
  {
    Node *currt = start;
    while(currt->next->pno>=pno)
    {
      currt=currt->next;
    }
    n->next=currt->next;
    currt->next=n;
  }
}
void PriorityQueue::delete_high_pno()
{
  //Empty Queue:
  if(isEmpty())
  {
    throw Underflow;
  }
  //At least one Node:
  else
  {
    Node *t = start;
    start=start->next;
    delete t;
  }
}
int PriorityQueue::get_high_pno_ele()
{
  //Empty Queue:
  if(isEmpty())
  {
    throw Underflow;
  }
  return start->item;
}
int PriorityQueue::get_hight_pno()
{
  //Empty Queue:
  if(isEmpty())
  {
    throw Underflow;
  }
  return start->pno;
}