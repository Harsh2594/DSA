#include<iostream>
using namespace std;

/*Define a class and structure to implement Doubly circular linked list*/
struct Node{
  int item;
  Node *prev;
  Node *next;
};

class CDLL
{
  private:
    Node *head;
  public:
    CDLL(){head=nullptr;}
    ~CDLL()
    {
      Node *currt = head;
      while(currt->next!=currt)
      {
        deleteFirst();
      }
      delete currt;
      head=nullptr;
    }  
    void insertAtStart(int);
    void insertAtEnd(int);
    void insertAfter(Node*,int);
    Node* searchItem(int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(Node*); 
};

void CDLL::insertAtStart(int data)
{
  Node *n = new Node;
  n->item=data;
  n->next=nullptr;
  n->prev=nullptr;
  //Case-1: Empty list
  if(head==nullptr)
  {
    head=n;
    n->next=head;
    n->prev=head;
  }
  else{
  //Case-2:At least One Node:
  n->next=head;
  n->prev=head->prev;
  head->prev=n;
  head->prev->next=n;
  head=n;
  }
}

void CDLL::insertAtEnd(int data)
{
  Node *n = new Node;
  n->item=data;
  n->next=nullptr;
  n->prev=nullptr;
  //Case-1: Empty list
  if(head==nullptr)
  {
    head=n;
    n->next=head;
    n->prev=head;
  }
  //Case-2:At least One Node:
  else
  {
    n->next=head;
    n->prev=head->prev;
    head->prev->next=n;
    head->prev=n;
  }
}
void CDLL::insertAfter(Node *temp,int data)
{
  Node *n=new Node;
  n->item=data;
  n->next=nullptr;
  n->prev=nullptr;
  //Case-1 Empty list:
  if(head==nullptr)
  {
    cout << "Cannot insert after a NULL node!" << endl;
    return;
  }
  //Verify that temp exists in the list
  Node *t = head;
  do
  {
    if(t==temp){break;}
    t=t->next;
  } while (t!=head);
  if(t!=temp)
  {
    cout << "Specified node does not belong to the list!" << endl;
    return;
  }
  //insertion after temp
  n->next=temp->next;
  n->prev=temp;
  temp->next->prev=n;
  temp->next=n;
}

Node* CDLL::searchItem(int data)
{
  if(head==nullptr){return nullptr;}
  Node *t = head;
  do
  {
    if(t->item==data){return t;}
    t=t->next;
  } while (t!=head);
  return nullptr;
  
}

void CDLL::deleteFirst()
{
  //Case-1: Empty list
  if(head==nullptr){return;}
  //Case-2: Only one Node:
  if(head->next==head)
  {
    delete head;
    head=nullptr;
    return;
  }
  //Case-3: More Than One Node:
  Node *currt = head;
  Node *t = head->next;
  head->prev->next=head->next;
  t->prev=head->prev;
  head = t;
  delete currt;
}

void CDLL::deleteLast()
{
  //Case-1: Empty list
  if(head==nullptr){return;}
  //Case-2: Only one Node:
  if(head->next==head)
  {
    delete head;
    head=nullptr;
    return;
  }
  //Case-3: More Than One Node:
  Node *currt = head->prev;
  Node *t = head->prev->prev;
  t->next=head;
  head->prev=t;
  delete currt;

}

void CDLL::deleteNode(Node *temp)
{
 //Empty list
  if(head==nullptr)
  {
    cout << "List is empty, nothing to delete!" << endl;
    return;
  }
  if(temp!=nullptr)
  {
    if(temp==head)
    {
      deleteFirst();
      return;
    }
    else if(temp==head->prev)
    {
      deleteLast();
      return;
    }
    else
    {
      Node *t = head->next;
      while(t!=temp&&t!=head)
      {
        t=t->next;
      }
      if(t!=temp)
      {
        cout << "Node not found in the list!" << endl;
        return;
      }
      t->prev->next=t->next;
      t->next->prev=t->prev;
      // delete temp;//temp might not always be trustworthy (e.g., caller passes a random pointer or one already freed).
      delete t; //t is guaranteed to be valid since you reached it by following next pointers starting from head.
    }
  }

  
  
}