#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int>>adj;
public:
   void addedge(int u,int v)
   {
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   bool bfs(int src)
   {
       map<int,int>visited;
       map<int,int>parent;
       for(auto p : adj){
       visited[p.first]=parent[p.first]=0;
       }

        if(contain_cycle(src,visited,parent))
          return true;
        else
          return false; 
   }
   bool contain_cycle(int node,map<int,int> &visited,map<int,int> &parent)
   {
       queue<int>q;
       q.push(node);
       visited[node]=1;
       parent[node]=-1;
       while(!q.empty())
       {
           int p = q.front();
           q.pop();
           
          for(auto i : adj[p])
          {
              if(i==parent[p]) continue;

              if(!visited[i])
              {
                  q.push(i);
                  visited[p]=1;
                  parent[i]=p;
              }
              else
                return true;
          }
       }
       return false;
   }
};
int main()
{
    graph g;
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(2,3);
    if(g.bfs(0))
    cout<<"It is not a tree";
    else
    cout<<"It is a tree";
}
