#include<bits/stdc++.h>
using namespace std;
int countt=0;
class graph
{
public:
    map<int,list<int>>adj1;
    map<int,list<int>>adj2;
    stack<int>s;
    void addedge(int u,int v)
    {
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    void dfs(int n)
    {
       int visited[n]={0};
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
              {
                  dfsHelper(i,visited);
              }
        }
    }
    void dfsHelper(int i,int visited[])
    {
        visited[i]=1;
        for(auto nbr : adj1[i])
        {
            if(!visited[nbr])
            {
                dfsHelper(nbr,visited);
            }
        }
        s.push(i);
    }
    void dfs_after_Transverse(int n)
    {
        int visited[n]={0};
        while(!s.empty())
        {
            int topp = s.top();
            s.pop();
            if(!visited[topp])
            {
                dfsHelper_after_Transverse(topp,visited);
                cout<<endl;
                countt++;
            }
        }
    }
    void dfsHelper_after_Transverse(int i,int visited[])
    {
        visited[i]=1;
         cout<<i<<" ";
        for(auto nbr : adj2[i])
        {
            if(!visited[nbr])
            {
                dfsHelper_after_Transverse(nbr,visited);
            }
        }
    }
};
int main()
{
    graph g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);
    g.addedge(2,4);
    g.addedge(4,5);
    g.addedge(5,6);
    g.addedge(6,4);
    g.addedge(7,6);
    g.addedge(7,8);
    g.addedge(8,7);
    g.addedge(8,9);
    g.dfs(10);
    g.dfs_after_Transverse(10);
    cout<<countt;
}
