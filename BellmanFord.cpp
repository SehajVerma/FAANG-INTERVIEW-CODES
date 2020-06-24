#include <bits/stdc++.h>
using namespace std;
class Edges
{
public:
    int src;
    int dest;
    int weight;
};
Edges edges[100000];
vector<int> Bellman_Ford(int source,int no_of_vertices)
{
    vector<int>dis(no_of_vertices,INT_MAX);
    dis[source]=0;
    for(int i=0;i< no_of_vertices-1;i++)
    {
        for(auto x:edges)
        {
            if(dis[x.src]!=INT_MAX && dis[x.dest] > dis[x.src] + x.weight)
            {
                dis[x.dest] = dis[x.src] + x.weight;
            }
        }
    }
    for(auto x:edges)
        {
            if(dis[x.src]!=INT_MAX && dis[x.dest] > dis[x.src] + x.weight)
            {
                cout<<"Negative weight Cycle exists";
                exit(0);
            }
        }
    return dis;
}
int main() {
    int no_of_edges;
    int no_of_vertices;
    cin>>no_of_vertices>>no_of_edges;

    for(int i=0;i<no_of_edges;i++)
    {
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
    vector<int>dis = Bellman_Ford(0,no_of_vertices);
    
    for(int i=0;i<no_of_vertices;i++)
    {
        cout<<"Distance of src to "<<i<<" is "<<dis[i]<<endl;
    }
}
