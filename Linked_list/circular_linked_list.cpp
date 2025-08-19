#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node* next;
};

class CLL
{
  private:
    Node* head;
  public:
    CLL(){head=nullptr;}
    ~CLL()
    {
      if(head==nullptr){return;}
      Node *curr = head->next;
      Node*temp;
      while(curr!=head)
      {
        temp=curr;
        curr=curr->next;
        delete temp;
      }
      delete head;
      head=nullptr;
    }
    // ~CLL()
    // {
    //   if (head == nullptr)  // Empty list
    //     return;
    //   Node *t = head;
    //   while(t->next!=head)
    //   {
    //     Node *n = t;
    //     t=t->next;
    //     delete n;
    //   }
    //   delete t;
    //   head=nullptr;
    // }
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
  Node *n= new Node;
  n->data=data;
  //Case-1 Empty list
  if(head==nullptr)
  {
    head=n;
    n->next=head;
  }
  //Case-2 At least One Node:
  else
  {
    Node *currt = head;
    while(currt->next!=head)
    {
      currt=currt->next;
    }
    currt->next=n;
    n->next=head;
    head=n;
  }  
}

void CLL::insertAtEnd(int data)
{
  Node *n = new Node;
  n->data=data;
  n->next=nullptr;
  //Case-1 Empty list
  if(head==nullptr)
  {
    head=n;
    n->next=head;
  }
  //Case-2 At least One Node
  else
  {
    Node *currt = head;
    while(currt->next!=head)
    {
      currt=currt->next;
    }
    currt->next=n;
    n->next=head;
  }
}
void CLL::insertAfter(Node *temp,int data)
{
  //Create a Node
  Node *n = new Node;
  n->data=data;
  n->next=nullptr;
  //Case-1 Empty list
  if(temp==nullptr)
  {
    cout << "Cannot insert after a NULL node!" << endl;
    return;
  }
  //Case-2 At least one Node
  else
  {
    if(temp->next!=head) //if given node is not last node
    {
     n->next=temp->next;
     temp->next=n;
    } 
    else                //if given node is last node
    {
      n->next=head;
      temp->next=n;
    }
  }
}

Node* CLL::searchItem(int data)
{
  if(head==nullptr)
    return nullptr;

  Node *currt = head->next;
  do
  {
    if(currt->data==data)
    {
      return currt;
    }
    currt = currt->next;
  }while(currt!=head->next);
  
  return nullptr;  
}

void CLL::deleteFirst()
{
  if(head==nullptr)// Case 1: Empty list
    return;
  if(head->next==head)// Case 2: Only one node(if we not consider this case then we have face Dangling pointer(pointed to memory which is freed) problem)
  {
    delete head;
    head=nullptr;  
    return;
  }  
  // Case 3: More than one node
  Node *t;
  t = head;
  Node *currt = head;
  while(currt->next!=head)
  {
    currt=currt->next;
  }
  currt->next=head->next;
  head=head->next;
  delete t;
}
void CLL::deleteLast()
{
  if(head==nullptr)// Case 1: Empty list
    return;
  if(head->next==head)// Case 2: Only first node is last(if we not consider this case then we have face Dangling pointer(pointed to memory which is freed) problem)
  {
    delete head;
    head=nullptr;  
    return;
  }   
  // Case 3: More than one node 
  
  Node *currt = head;
  while(currt->next->next!=head)
  {
    currt=currt->next;
  }
  Node *t=currt->next;
  currt->next=head;
  delete t;
}

void CLL::deleteNode(Node *temp)
{
  //Case-1 handle empty list
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
    } 
    else
    {
      Node *t=head;
      while(t->next!=temp&&t->next!=head)//handle infinite loop by adding t->next!=head
      {
        t=t->next;
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

