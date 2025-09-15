#include<iostream>
using namespace std;
#define INVALID_INDEX 1;
class GraphMatrix
{
  private:
    int v_count;
    int e_count;
    int **adj; //pointer point to array of pointers:
  public:
   void createGraph(int,int);  
   void printGraph();
   void print_Adj_Nodes(int);
   bool check_isolated_Node(int);
};

void GraphMatrix::createGraph(int vno,int eno)
{
  int u,v; //Two nodes given by user jinke beech me edge hai
  v_count=vno;
  e_count=eno;
  adj = new int*[v_count]; //create pointers for each row 
  for(int i=0;i<v_count;i++) //create column for each row 
    adj[i] = new int[v_count];
  //set defalut value zero  
  for(int i=0;i<v_count;i++)
    for(int j=0;j<v_count;j++)
      adj[i][j]=0;
  //node connection between edge
  for(int k=1;k<=e_count;k++)
  {
    cout<<"\nEnter node numbers connection edge: ";
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
  }    
}

void GraphMatrix::printGraph()
{
  cout<<endl;
  for(int i=0;i<v_count;i++){
    for(int j=0;j<v_count;j++)
      cout<<adj[i][j]<<" ";
    cout<<endl;
  }    
}

void GraphMatrix::print_Adj_Nodes(int node)
{
  if(node>=v_count||node<0)
    throw INVALID_INDEX;
  for(int i=0;i<v_count;i++)
    if(adj[node][i]!=0)
      cout<<i<<",";
}

bool GraphMatrix::check_isolated_Node(int node)
{
  bool flag = true;
  if(node>=v_count||node<0)
    throw INVALID_INDEX;
  for(int i=0;i<v_count;i++)
  {
    if(adj[node][i]!=0)
    {
      flag=false;
      cout<<"Node "<<i<<"is not isolated."<<endl;
    }
  }  
  return flag;
}
