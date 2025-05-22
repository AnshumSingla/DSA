#include<iostream>
#include<list>
#include <unordered_map>
using namespace std;

class graph{

  public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
      //direction = 0 -> Undirected Graph
      //direction = 1 -> directed Graph

      //create an edge form u to v
      adj[u].push_back(v);

      if(direction == 0)
        adj[v].push_back(u);
    }

    void printAdjList(){
      for(auto i:adj){
        cout<<i.first<<"->" ;
        for(auto j:i.second){
          cout<<j<<", ";
        }
        cout<<endl;
      }
    }
};

int main(){

  int n, m;
  cout<<"Enter the number of nodes"<<endl;
  cin>>n;
  cout<<"Enter the number of edges"<<endl;
  cin>>m;

  graph g;

  for (int i = 0; i < m; i++)
  {
    int u,v;
    cin>>u>>v;
  }
  
  return 0;
}