#include <bits/stdc++.h>
using namespace std;

//If generic data type to be given
//template<typename T>

class graph
{
    map<int,list<int>>adj;
    list<int>l;
public:
   void addedge(int u,int v)
   {
       adj[u].push_back(v);
   }
   void Topological_Sort()
   {
       map<int,int>visited;
       for(auto p : adj)
        visited[p.first]=0;

       for(auto p : adj)
       {
           if(!visited[p.first])
           {
               dfs(p.first,visited);
           }
       }
       for(auto node : l)
       cout<<node<<" ";
   }
   void dfs(int node,map<int,int> &visited)
   {
       visited[node]=1;
       for(auto child : adj[node])
       {
           if(!visited[child])
           {
               dfs(child,visited);   
           }
       }
       l.push_front(node);
   }
};
int main()
{
    graph g;
    
    //If generic  graph<T> g;  //graph<string> g
     
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,3);
    g.addedge(3,2);
    g.Topological_Sort();
}
