#include<iostream>
using namespace std;
#define Stack_Underflow 1;
/*Define a Stack data structure Using Linked_list*/
struct Node
{
  int item;
  Node *next;
};

class Stack
{
  private:
    Node *top;
  public:
    Stack()
    {
      top=nullptr;
    }  
    ~Stack()
    {
      while(top!=nullptr)
      {
        Node *t = top;
        top=top->next;
        delete t;
      }
    }
    //push new node in stak
    void push(int data)
    {
      Node *n = new Node;
      n->item=data;
      n->next=nullptr;
      //Case-1: Empty linked list
      if(top==nullptr)
      {
        top = n;
      }
      else
      {
        //Case-2: At least One Node:
        n->next=top;
        top=n;
      }  
    }
    //Check stack is empty:
    bool isEmpty()
    {
      return(top==nullptr);
    }

    //Delete top node of stack:
    int pop()
    {
      if(top==nullptr)
      {
        throw Stack_Underflow;
      }
      //Case-1 Only One node
      else if(top->next==nullptr)
      {
        int data;
        Node *t = top;
        data = t->item;
        top = nullptr;
        delete t;
        return data;
      }
      //Case-2 More than One Node
      else
      {
        int data;
        Node *t = top;
        data = t->item;
        top = top->next;
        delete t;
        return data;
      }
    }
    //Show top element of stack:
    void peek()
    {
      cout << "top element: " << top->item << endl;
    }
    //Reverse stack
    void reverse_stack(Stack &s)
    {
      Stack s1;
      while(!s.isEmpty())
      {
        s1.push(s.pop());
      }
      Stack s2;
      while(!s1.isEmpty())
      {
        s2.push(s1.pop());
      }
      while(!s2.isEmpty())
      {
        s.push(s2.pop());
      }
    }
    void check_palindrome(Stack &s)
    {
      Stack temp; 
      Stack result;
      //Make copy of stack
      for (Node* curr = s.top; curr != nullptr; curr = curr->next)
            temp.push(curr->item);
      for (Node* curr = temp.top; curr != nullptr; curr = curr->next)
            result.push(curr->item);      

      reverse_stack(s);
      
      while(!s.isEmpty())
      {
        if(s.pop()!=result.pop())
        {
          cout<<"Not a palindrome Number"<<endl;
          return;
        }
      }
      cout<<"Palindrome Numbers"<<endl;

    }
};

int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.check_palindrome(s);
  


}