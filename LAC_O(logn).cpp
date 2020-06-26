#include <bits/stdc++.h>
using namespace std;
int ht=0;
int height[100];
int parent[100];
class node
{
    public:
      int data;
      node *left;
      node *right;
      node(int d)
      {
          data=d;
          left=right=NULL;
      }
};
node *head=NULL;
void insertnode(int *a,int n)
{
    head = new node(a[0]);
    int i=1;
    queue<node*>q;
    q.push(head);

    for(int i=0;i<n;i++)
        parent[i]=-1;

    while(!q.empty())
    {
        node *p = q.front(); q.pop();
        //cout<<p->data<<" ";
        ht++;
        if(a[i]!=-1)
        {

            p->left = new node(a[i]);
            q.push(p->left);
            parent[a[i]]=p->data;
        }
        i++;
        if(a[i]!=-1)
        {
            p->right = new node(a[i]);
            q.push(p->right);
            parent[a[i]]=p->data;
        }
        i++;
    }
}
void dfs(int src,int parent)
{
}
int LAC(int a,int b)
{
    if(height[a]>height[b]) swap(a,b);
    int d = height[b] - height[a];
    cout<<"hello";
    while(d > 0)
    {
        b = parent[b];
        d--;
    }
    if(a==b)
    return a;

    while(parent[a]!=parent[b])
    {
        a = parent[a];
        b = parent[b];
    }
    return parent[a];
}
int main()
{
    int a[] = {1,2,3,5,6,-1,-1,4,-1,-1,7,-1,8,-1,-1,-1,-1};
    insertnode(a,sizeof(a)/4);
    for(int i=0;i<sizeof(a)/4;i++)
    cout<<height[i]<<" "<<parent[i]<<endl;
    //cout<<LAC(4,6);
}
https://github.com/rachitiitr/DataStructures-Algorithms/blob/master/Library/Tree/dp-on-tree-type-c-LCA.cpp
