#include<bits/stdc++.h>
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
int countNodes(node *root)
{
    if(root==NULL)
    return 0;

    return countNodes(root->left)+countNodes(root->right)+1;
}
node *findNode(node *root,int find)
{
    if(root==NULL)
    return NULL;

    if(root->data==find)
    return root;

    node *left = findNode(root->left,find);
    node *right =  findNode(root->right,find);


    return left==NULL?right:left;
}
node *createTree()
{
   int data;
   cin>>data;
   if(data==-1) return NULL;
   node *root = new node(data);
   root->left=createTree();
   root->right=createTree(); 
   return root;
}
void preorder(node *root)
{
    if(!root)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n,na,find;
    cin>>n>>na>>find;
    node *root=NULL;
    root = createTree();
    node *findroot = findNode(root,find);
    int nleft = countNodes(findroot->left);
    int nright = countNodes(findroot->right);
    int nparent = na-(nleft+nright)-1;
    if(nleft>na-(nright+nparent))
    cout<<"1";
    else if(nright>na-(nleft+nparent))
       cout<<"1";
         else if(nparent>(nleft+nright))
           cout<<"1";
              else 
                cout<<"0";
    //preorder(root);
}
