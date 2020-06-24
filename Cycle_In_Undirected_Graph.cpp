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
   bool CycleInUnDirectedGraph(int n)
   {
       bool visited[n];
       for(int i=0;i<n;i++)
       visited[i]=false;

       for(int i=0;i<n;i++)
       {
           if(!visited[i])
           {
               if(contain_cycle(i,-1,visited))
               return true;
           }
       }
       return false;
   }
   bool contain_cycle(int node,int parent,bool *visited)
   {
       visited[node]=true;

       for(auto nbr : adj[node])
       {

          if(!visited[nbr])
          {
              bool cycle_mila = contain_cycle(nbr,node,visited);
              if(cycle_mila) return true;
          }
         else
           if(nbr!=parent)
             return true;
       }
       return false;
   }
};
int main() {
     graph g;
     g.addedge(0,1);
     g.addedge(1,2);
     g.addedge(2,3);
     g.addedge(3,4);
     g.addedge(4,2);
     g.addedge(4,5);
     g.addedge(5,6);
     g.addedge(1,5);
    cout<<g.CycleInUnDirectedGraph(7);
}
