#include<iostream>
using namespace std;
/*Define a circular linked list Data Structure in which pointer point to last node not first node;*/
struct Node
{
  int item;
  Node *next;
};

class CLL
{
  private:
    Node *tail;
  public:
      CLL(){tail=nullptr;}
      ~CLL()
      {
        if(tail==nullptr){return;}
        Node *currt=tail->next;
        Node *temp;
        do
        {
          temp=currt;
          currt=currt->next;
          delete temp;
        } while (currt!=tail);
        delete currt;
        tail=nullptr;
      }
      void insertAtStart(int);
      void insertAtEnd(int);
      void insertAfter(Node*,int);
      Node* searchItem(int);
      void deleteFirst();
      void deleteLast();
      void deleteNode(Node*);
  };

void CLL::insertAtStart(int data)
{
  Node *n=new Node;
  n->item=data;
  n->next=nullptr;
  //Case-1 Empty list:
  if(tail==nullptr)
  {
    n->next=n;
    tail=n;
  }
  //Case-2 At least One Node
  else
  {
    n->next=tail->next;
    tail->next=n;
  }
}
void CLL::insertAtEnd(int data)
{
  Node *n=new Node;
  n->item=data;
  n->next=nullptr;
  //Case-1 Empty list:
  if(tail==nullptr)
  {
    n->next=n;
    tail=n;
  }
  //Case-2 At least One Node
  else
  {
    n->next=tail->next;
    tail->next=n;
    tail=n;
  }
}
void CLL::insertAfter(Node *temp,int data)
{
  Node *n=new Node;
  n->item=data;
  n->next=nullptr;
  //Case-1 Empty list:
  if(tail==nullptr)
  {
    cout << "Cannot insert after a NULL node!" << endl;
    return;
  }
  //Case-2 At least One Node
  else
  {
    if(temp!=tail) 
    {
      n->next=temp->next;
      temp->next=n;
    }
    else //if insert after last node;
    {
      n->next=tail->next;
      tail->next=n;
      tail=n;
    }
  }
}
Node* CLL::searchItem(int data)
{
  if(tail==nullptr){return nullptr;}
  Node *t = tail->next;
  do
  {
    if(t->item==data)
      return t;
    t=t->next;  
  } while (t!=tail->next);
  return nullptr;
}

void CLL::deleteFirst()
{
  //Case-1:Empty list:
  if(tail==nullptr){return;}
  //Case-2:Only One Node:
  if(tail->next==tail)
  {
    delete tail;
    tail=nullptr;
    return;
  }
  //Case-3:More than one Node:
  Node *currt = tail->next;
  tail->next=tail->next->next;
  delete currt;
  return;

}
void CLL::deleteLast()
{
  //Case-1:Empty list:
  if(tail==nullptr){return;}
  //Case-2:Only One Node:
  if(tail->next==tail)
  {
    delete tail;
    tail=nullptr;
    return;
  }
  //Case-3:More than one Node:
  Node *t = tail;
  Node *currt = tail->next;
  while(currt->next!=tail)
  {
    currt=currt->next;
  }
  currt->next=tail->next;
  tail=currt;
  delete t;
}

void CLL::deleteNode(Node *temp)
{
  //Empty list
  if(tail==nullptr)
  {
    cout << "List is empty, nothing to delete!" << endl;
    return;
  }
  if(tail!=nullptr)
  {
    if(temp==tail)  //check last node
      deleteLast();
    else if(temp==tail->next)//check first node
      deleteFirst();  
    else
    {
      Node *t = tail->next;
      while(t->next!=temp&&t->next!=tail)
      {
        t = t->next;
      }
      if(t->next!=temp)// Not found in list
      {
        cout << "Node not found in the list!" << endl;
        return;
      }
      t->next=temp->next;
      delete temp;
    }  
  }
}
