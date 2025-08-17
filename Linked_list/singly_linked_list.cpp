#include<iostream>
using namespace std;

/*Define a class SLL to implement singly linked list data struture with memeber variable start pointer
 of type node*/
struct Node
{
  int data;
  Node* next;
};

class SLL
{
  private:
    Node* head;
  public:
    SLL(){head=nullptr;}
    ~SLL(){delete []head;}
    void insertAtStart(int);
    void insertAtEnd(int);
    void insertAfter(Node*,int);
    Node* searchItem(int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(Node*);
};

void SLL::insertAtStart(int data)
{
  Node *n = new Node;
  n->data=data;
  n->next=head;
  head = n;
}
void SLL::insertAtEnd(int data)
{
  Node *n = new Node;
  n->data=data;
  n->next=nullptr;
  Node *temp;
  if(head==nullptr)
    head=n;
  else
    temp->next=head;
    while(temp->next!=nullptr) 
    {
      temp = temp->next;
    } 
    temp->next = n;
}
Node* SLL::searchItem(int data)
{
  Node *temp;
  temp->next=head;
  while(temp->next!=nullptr)
  {
    if(temp->data==data)
      return temp;
    temp = temp->next;
  }  
  return nullptr;  
}

void SLL::insertAfter(Node *temp,int data)
{
  Node*t = searchItem(temp->data);
  Node *n = new Node;
  n->data=data;
  n->next=t->next;
  t->next=n;
}
void SLL::deleteFirst()
{
  if(head!=nullptr)
    head = head->next->next;
}
void SLL::deleteLast()
{
  Node *temp;
  temp = head;
  while(temp->next->next!=nullptr)
    temp=temp->next;
  temp->next=nullptr;  
}
void SLL::deleteNode(Node*temp)
{
  Node *t;
  t = head;
  while(t->next->data!=temp->data)
    t = t->next;
  t->next = temp->next;  
}

