#include <bits/stdc++.h>
using namespace std;

int n;
int indegree[1000]={0};
class graph
{
    map<int,list<int>>adj;
public:
   void addedge(int u,int v)
   {
       adj[u].push_back(v);
       indegree[v]++;
   }
   void Topological_Sort_BFS()
   {
       queue<int>q;
       for(int i=0;i<n;i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           cout<<node<<" ";
           for(auto p : adj[node])
           {
               indegree[p]--;
               if(indegree[p]==0)
               q.push(p);
           }
       }
   }
};
int main()
{
    graph g;

    cin>>n;
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(2,5);
    g.addedge(4,5);
    g.addedge(3,5);
    g.Topological_Sort_BFS();
}
