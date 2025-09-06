#include<iostream>
using namespace std;
#define Tree_is_null 1;
/*Define a class BST(Binary search tree) with node type pointer root as member
variable.Implement Binary Search Tree using linked representation.*/

struct Node
{
  int item;
  Node *right;
  Node *left;
};
class BST
{
  private:
    Node *root;
  protected:
    void preorder_rec(Node*);  
    void Inorder_rec(Node*);  
    void postorder_rec(Node*);  
    Node*deleterec(Node*,int);
  public:
    BST()
    {
    root=nullptr;
    }  
    ~BST()
    {
      while(root!=nullptr)
      {
        del(root->item);
      }
    }
    bool isEmpty()
    {
      return root==nullptr;
    }

    void insert(int data)
    {
      Node *n = new Node;
      n->item=data;
      n->right=nullptr;
      n->left=nullptr;
      if(isEmpty())
      {
        root = n;
      }
      else
      {
        Node*currt = root;
        Node*parent = nullptr;
        while(currt!=nullptr)
        {
          parent=currt;
          if(data<currt->item)
            currt = currt->left;
          else
            currt = currt->right;  
        }
        if(data<parent->item)
          parent->left=n;
        else
          parent->right=n;  
      }
    }

    void preorder();
    void Inorder();
    void postorder();
    void del(int);
    Node* search_item(int);

};
void BST::preorder()
{
  preorder_rec(root);
}
void BST::preorder_rec(Node* node)
{
  if(node==nullptr){return;}
  cout<<node->item<<",";
  preorder_rec(node->left);
  preorder_rec(node->right);
}
void BST::Inorder()
{
  Inorder_rec(root);
}
void BST::Inorder_rec(Node* node)
{
  if(node==nullptr){return;}
  preorder_rec(node->left);
  cout<<node->item<<",";
  preorder_rec(node->right);
  
}
void BST::postorder()
{
  postorder_rec(root);
}
void BST::postorder_rec(Node* node)
{
  if(node==nullptr){return;}
  preorder_rec(node->left);
  preorder_rec(node->right);
  cout<<node->item<<",";
}

Node* BST::deleterec(Node* node,int data)
{
  //Empty tree:
  if(node==nullptr){return node;}
  //Go left:
  if(data<node->item)
  {
    node->left=deleterec(node->left,data);
    return node;
  }
  //Go right:
  else if(data>node->item)
  {
    node->right=deleterec(node->left,data);
    return node;
  }
  else
  {
    //Node found:
    //leaf Node:
    if(node->left==nullptr&&node->right==nullptr)
    {
      delete node;
      return nullptr;
    }
    //only one child:
    else if(node->left==nullptr||node->right==nullptr)
    {
      Node*child = node->left!=nullptr?node->left:node->right;
      delete node;
      return child;
    }
    //Two child:
    else
    {
      Node *child = node->left;
      Node *parent = node;
      while(child->right!=nullptr)
      {
        parent=child;
        child=child->right;
      }
      if(parent!=node)
      {
        parent->right=child->left;
        child->left=node->left;
        child->right=node->right;
        delete node;
        return child;
      }
      else
      {
        child->right=parent->right;
        delete node;
        return child;
      }
    }
  }
}
void BST::del(int data)
{
  root = deleterec(root,data);
}
Node* BST::search_item(int data)
{
  Node *currt = root;
  while(currt!=nullptr)
  {
    if(currt->item==data)
      return currt;
    if(currt->item>data)
      currt=currt->right;
    else
      currt=currt->left;    
  }
  return nullptr;
}



int main() {
    BST tree;

    // Build tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);  // <-- leaf node
    tree.insert(40);

    cout << "Inorder before deletion: ";
    tree.Inorder();

    // Delete a leaf node
    tree.del(20);

    cout << "Inorder after deletion: ";
    tree.Inorder();

    return 0;
}
  
