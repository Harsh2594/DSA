#include<iostream>
using namespace std;

/*Define a class DLL to implement singly linked list data struture with memeber variable start pointer
 of type node*/

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

class DLL
{
  private:
    Node *head;
  public:
    DLL(){head=nullptr;}
    ~DLL()
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

void DLL::insertAtStart(int data)
{
  Node *n = new Node;
  n->data=data;
  n->next=head;
  n->prev=nullptr;
  if(head!=nullptr)//check if list is not empty.
    head->prev=n;
  head=n;
}
void DLL::insertAtEnd(int data)
{
  Node *n = new Node;
  n->next=nullptr;
  n->prev=nullptr;
  if(head!=nullptr)
  {
    Node *t;
    t = head;
    while(t->next!=nullptr)
    {
      t=t->next;
    }
    t->next=n;
    n->prev=t;
  }
  else
    cout<<"wrong function called!"<<endl;
}

Node* DLL::searchItem(int data)
{
  Node *temp;
  temp=head;
  if(head==nullptr)
    cout<<"Node not avialable!";
  else
    while(temp!=nullptr)
    {
      if(temp->data==data)
      {
        return temp;
      }
      temp=temp->next;
    }  
    return nullptr;  
}

void DLL::insertAfter(Node *temp,int data)
{
  if(temp!=nullptr)
  {
    Node *t;
    t = head;
    while(t!=nullptr)
    {
      if(t==temp)
        break;
      t=t->next;  
    }
    if(t==nullptr)
    {
      cout<<"Specified node does not belong to the list";
      return;
    }  
    else
    {
      Node *n=new Node;
      n->data=data;
      n->next=temp->next;
      n->prev=temp;
      temp->next->prev=n;
      temp->next=n;
    }  
  }
}

void DLL::deleteFirst()
{
  if(head==nullptr)
    return;
  Node *t;
  t=head;
  head=head->next;  
  if(head!=nullptr)
    head->prev=nullptr;
  delete t;  
} 

void DLL::deleteLast()
{
  if(head==nullptr)
    return;
  if(head!=nullptr)
  {
    Node *t;
    if(head->next==nullptr)
    {
      delete head;
      head=nullptr;
    }
    else
    {
      t=head;
      while(t->next->next!=nullptr)
      {
        t = t->next;
      }
      delete t->next;
      t->next=nullptr;
    }
  }  

}

void DLL::deleteNode(Node*temp)
{
 if(temp==nullptr){return;}
 if(temp==head)
 {
  deleteFirst();
  return;
 }
 if(temp->next!=nullptr)
  temp->prev->next=temp->next;
 if(temp->prev!=nullptr)
  temp->next->prev=temp->prev;
 delete temp;  

}

