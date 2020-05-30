#include <bits/stdc++.h>
using namespace std;
class node
{
public:
     node *left;
     node *right;
     int data;
     node(int d)
     {
         data=d;
         left=right=NULL;
     }
};
int findmax(int *a,int s,int e)
{
    int max=INT_MIN;
    int j=s;
    for(int i=s;i<=e;i++)
    {
        if(a[i]>max){
        max=a[i];
        j=i;
        }
    }
    return j;
}
node *createTree(node *root,int *a,int s,int e)
{
    if(s>e)
    return NULL;
    if(s==e)
    return new node(a[s]);
    int i = findmax(a,s,e);
    root = new node(a[i]);
    root->left = createTree(root,a,s,i-1);
    root->right = createTree(root,a,i+1,e);
    return root;
}
void inorder(node *root)
{
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    node *root=NULL;
    root = createTree(root,a,0,n-1);
    inorder(root);
return 0;
}
