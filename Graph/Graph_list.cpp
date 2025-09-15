#include<iostream>
using namespace std;

struct Node
{
  int item; //optional,used for weighted graph
  int vertex;
  Node *next;
};

class AdjList
{
  private:
    int vertex;
    Node *start;
  public:
    AdjList()
    {
      start=nullptr;
    }
    AdjList(int);
    Node* getstart();
    void SetVertex(int);
    void Add_Node(int,int);
    void removeFristNode();
    void PrintList();
    ~AdjList();
};

AdjList::AdjList(int v)
{
  start=nullptr;
  vertex=v;
}
Node* AdjList::getstart()
{
  return start;
}
void AdjList::SetVertex(int v)
{
  vertex=v;
}
void AdjList::Add_Node(int v,int data)
{
  Node *n = new Node;
  n->vertex=v;
  n->item=data;
  n->next=start;
  start=n;
}
void AdjList::removeFristNode()
{
  Node *t = start;
  start = start->next;
  delete t;

}
void AdjList::PrintList()
{
  cout<<vertex<<"->";
  Node *t = start;
  while(t)
  {
    cout<<" ("<<t->vertex<<","<<t->item<<")";
    t=t->next;
  }
}  
  AdjList::~AdjList()
  {
    removeFristNode();
  }

int main()
{
  AdjList l1;
  l1.SetVertex(0);
  l1.Add_Node(1,5);
  l1.Add_Node(2,8);
  l1.Add_Node(3,4);
  l1.PrintList();
  return 0;
}