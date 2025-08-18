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
    ~SLL()
    {
      while(head!=nullptr)
        deleteFirst();
    }
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
  if(temp!=nullptr)
  {
    //check if temp is a valid node in the list
    Node *t;
    t=head;
    while(t!=nullptr)
    {
      if(t==temp)
        break;
      t = t->next;
    }
    if(t==nullptr)
      cout<<"Specified node does not belong to the list";
    else
      {
        //make a new Node:
        t = new Node;
        t->data=data;
        t->next=temp->next;
        temp->next=t;
      }  

  }
}
void SLL::deleteFirst()
{
  if(head!=nullptr)
  {
    Node *t;
    t = head;
    head=head->next;
    delete t;
  }
}
void SLL::deleteLast()
{
 if(head!=nullptr)
 {
  Node *t;
  if(head->next==nullptr)//single node in the list
  {
    delete head;
    head=nullptr;
  }
  else{
    t=head;
    while(t->next->next!=nullptr)
    {
      t=t->next;
    }
    delete t->next;
    t->next=nullptr;
  }
 }
}
void SLL::deleteNode(Node*temp)
{
  if(temp!=nullptr)
  {
    Node *t = searchItem(temp->data);
    if(t==temp)
    {
      t = head;
      if(temp==head)
        deleteFirst();
      else
      {
        while(t->next!=temp)
        {
          t = t->next;
        }
        t->next=temp->next;
        delete temp;
      }  
    }
  }
}

