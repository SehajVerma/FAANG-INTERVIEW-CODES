#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj(50,vector<int>());
class graph
{
  public:
  void addedge(int u,int v)
  {
      adj[u].push_back(v);
      //adj[v].push_back(u);
  }
  void bfs(int src,int dest)
  {
      queue<int>q;
      int visited[50]={0};
      int dist[50]={0};
      int parent[50]={-1};
      q.push(src);

      dist[src]=0;

      visited[src]=1;
      while(!q.empty())
      {
          int topp=q.front();
          q.pop();
          cout<<topp<<" ";
         for(int i:adj[topp])
         {
             if(!visited[i])
             {
                 visited[i]=1;
                 q.push(i);

                 dist[i]=dist[topp]+1;
                 parent[i]=topp;
             }
         }

      }
      cout<<endl;
      int temp=dest;
      while(temp!=-1)
      {
          cout<<temp<<"<-";
          temp = parent[temp];
      }
  }
};
int main() {
    graph g;
    int board[50]={0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    for(int u=0;u<36;u++)
    {
        for(int dice=1; dice<=6; dice++)
        {
            int v = u + dice + board[u + dice];
            g.addedge(u,v);
        }
    }
    g.bfs(0,36);
}
