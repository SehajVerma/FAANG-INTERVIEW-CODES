#include <bits/stdc++.h>
using namespace std;
map<int,int>dist;
vector<int>parent(6,0);
class graph
{
    map<int,list<pair<int,int>>>adj;
    set<pair<int,int>>s;
    public:
      void addedge(int u,int v,int dist)
      {
          adj[u].push_back({v,dist});
          adj[v].push_back({u,dist});
      }
      void PrimsMST(int src)
      {
          for(auto it:adj)
          dist[it.first]=INT_MAX;

          vector<int>visited(6,0);

          s.insert({0,src});
          dist[src]=0;
          parent[src]=-1;
          while(!s.empty())
          {
              auto p = *(s.begin());
              int node = p.second;
              int nodeDist = p.first;
              visited[node]=1;
              s.erase(p);

              for(auto it:adj[node])
              {
                  if(!visited[it.first])
                  {
                      int dest = it.first;
                      int destDist = it.second;

                      if(dist[dest] > destDist)
                      {
                          dist[dest]=destDist;
                          auto f = s.find({destDist,dest});
                          if(f!=s.end())
                              s.erase(f);
                          s.insert({destDist,dest});
                        parent[dest]=node;
                          }
                      }
                  }
                  
              }
          }
};
int main() {
    graph g;
    g.addedge(0,1,7);
    g.addedge(0,2,8);
    g.addedge(1,2,3);
    g.addedge(1,3,6);
    g.addedge(2,4,3);
    g.addedge(3,4,2);
    g.addedge(2,3,4);
    g.addedge(3,5,5);
    g.addedge(4,5,2);
    g.PrimsMST(0);
    int cost=0;
    for(auto it:dist)
    cost += it.second;
    cout<<cost<<endl;

    for(int i=1;i<6;i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
}
