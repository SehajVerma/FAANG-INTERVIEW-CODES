#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>adj(4,vector<pair<int,int>>());
class graph
{
    public:
    void addedge(int u,int v,int dist)
    {
        adj[u].push_back({v,dist});
        adj[v].push_back({u,dist});
    }
    void dijkstra(int src)
    {
        map<int,int>dist;
        set<pair<int,int>>s;
        for(auto it:dist)
          dist[it.first] = INT_MAX;

        dist[src]=0;
        s.insert({0,src});
       
        while(!s.empty())
        {
            auto p = *(s.begin());
            int node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for(auto nbr : adj[node])
            {
                int dest = nbr.first;
                int destDist = nbr.second;
                if((nodeDist + destDist) < dist[dest] )
                {
                    auto f = s.find({destDist,dest});
                    if(f!=s.end())
                    s.erase(f);

                    dist[dest] = nodeDist + destDist;
                    s.insert({dist[dest],dest});
                }
            }
        }
        for(auto p : dist)
        cout<<"Distance of"<<p.first<<"from "<<src<<"is "<<p.second<<endl;
    }
};
int main() {
    graph g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(1,4,7);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.dijkstra(1);
    
}
