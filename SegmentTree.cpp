#include <bits/stdc++.h>
using namespace std;
void buildtree(int *tree,int *a,int index,int s,int e)
{
    if(s>e)
    return;
    if(s==e){
    tree[index]=a[s];
    return;
    }
    int mid=(s+e)/2;
    buildtree(tree,a,2*index,s,mid);
    buildtree(tree,a,2*index+1,mid+1,e);

    int left=tree[2*index];
    int right=tree[2*index+1];
    tree[index]=min(left,right);
}
int querytree(int *tree,int *a,int index,int s,int e,int l,int r)
{
    if(s>=l && e<=r)       //full overlap
    return tree[index];
    if(r<s || l>e)        //no overlap
    return INT_MAX;
    int mid=(s+e)/2;     //partial overlap

    int left = querytree(tree,a,2*index,s,mid,l,r);
    int right = querytree(tree,a,2*index+1,mid+1,e,l,r);
    return min(left,right);
}
void updatetreeNode(int *tree,int *a,int index,int s,int e,int i,int n)
{
    if(i<s || i>e)        //no overlap
    return;

    if(s==e){
    tree[index]=n;
    return;
    }
    

    int mid=(s+e)/2;      //partial overlap
    updatetreeNode(tree,a,2*index,s,mid,i,n);
    updatetreeNode(tree,a,2*index+1,mid+1,e,i,n);
    tree[index] =  min(tree[2*index],tree[2*index+1]);
    return;
}
void updatetreeRange(int *tree,int *a,int index,int s,int e,int l,int r,int n)
{
    if(s>r || e<l)     //no overlap
    return;

   if(s==e){
   tree[index]+=n;
   return;
   }
   
   int mid=(s+e)/2;  //partial overlap
   updatetreeRange(tree,a,2*index,s,mid,l,r,n);
   updatetreeRange(tree,a,2*index+1,mid+1,e,l,r,n);
   tree[index] =  min(tree[2*index],tree[2*index+1]);
   return; 
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int *tree = new int[4*n+1];
    buildtree(tree,a,1,0,n-1);
    //PrintTree
    for(int i=1;i<=2*n-1;i++)
    cout<<tree[i]<<" ";
    cout<<endl;
    //queryTree
    cout<<querytree(tree,a,1,0,n-1,1,3)<<endl;
    //UpdateTree
    updatetreeRange(tree,a,1,0,n-1,0,2,6);
    for(int i=1;i<=2*n-1;i++)
    cout<<tree[i]<<" ";
    cout<<endl;

}
