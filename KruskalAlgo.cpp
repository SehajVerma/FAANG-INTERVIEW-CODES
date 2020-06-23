#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
      int source;
      int dest;
      int weight;
};
Edge input[100000];
int parent[100000];
Edge output[10000];
bool comp(Edge a, Edge b)
{
    if(a.weight < b.weight)
    return true;

    return false;
}
int find(int v)
{
    if(parent[v]==v)
    return v;

    return find(parent[v]);
}
int main() {
    int n,E;
    cin>>n>>E;
    for(int i=0;i<E;i++)
    {
        cin>>input[i].source>>input[i].dest>>input[i].weight;
    }
    sort(input,input+E,comp);

    for(int i=0;i<n;i++)
    parent[i]=i;

    int sum=0;
    int countt=0;
    for(int i=0;i<E;i++)
    {
        int sParent = find(input[i].source);
        int dParent = find(input[i].dest);

        if(sParent != dParent)
        {
            sum+=input[i].weight;
            output[countt] = input[i];
            countt++;
            parent[sParent] = dParent;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<countt;i++)
    {
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }

}
