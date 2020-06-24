#include <bits/stdc++.h>
using namespace std;
class graph
{
    map<int,list<int>>adj;
public:
   void addedge(int u,int v)
   {
       adj[u].push_back(v);
   }
   bool CycleInDirectedGraph(int n)
   {
       bool visited[n];
       bool stack[n];
       for(int i=0;i<n;i++)
       visited[i]=stack[i]=false;

       for(int i=0;i<n;i++)
       {
           if(!visited[i])
           {
               if(contain_cycle(i,visited,stack))
               return true;
           }
       }
       return false;
   }
   bool contain_cycle(int node,bool *visited,bool *stack)
   {
       visited[node]=true;
       stack[node]=true;

       for(auto nbr : adj[node])
       {
           if(stack[nbr])
            return true;

          if(!visited[nbr])
          {
              bool cycle_mila = contain_cycle(nbr,visited,stack);
              if(cycle_mila) return true;
          }
       }
       stack[node]=false;
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
    cout<<g.CycleInDirectedGraph(7);
}
