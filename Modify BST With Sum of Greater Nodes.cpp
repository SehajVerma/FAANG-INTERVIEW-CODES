#include <bits/stdc++.h>
using namespace std;
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
void modify(node *root,int &sum)
{
    if(root==NULL)
    return;

    modify(root->right,sum);
    sum+=root->data;
    root->data=sum;
    modify(root->left,sum);
}
int sumreplace(BinaryTreeNode<int> *root,int sum){    // without pointer or static variable
    
    if(root == NULL)
        return 0;
    
    int right=sumreplace(root->right,sum);
    
    if(right==0){
        root->data=root->data+sum;
    }
    else{
    root->data=root->data + right;
    }
    
    int left=sumreplace(root->left,root->data);
    if(left==0)
        return root->data;
    else
        return left;
     
    
}
node *insertNode(vector<int>& v,node *root,int lower,int upper,int &root_idx)
{
    if(root_idx == v.size())
    return NULL;

    if(v[root_idx]<lower || v[root_idx]>upper)
    return NULL;

    root = new node(v[root_idx]);
    root_idx++;

    root->left = insertNode(v,root,lower,root->data,root_idx);
    root->right = insertNode(v,root,root->data,upper,root_idx);

    return root;
}

void printpreorder(node *root)
{
    if(!root)
    return;

    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int main() {
    int n;
    vector<int>v;
    node *root=NULL;
    while(cin>>n)
    {
        if(n!=-1)
        v.push_back(n);
    }
    int lower=INT_MIN;
    int upper=INT_MAX;
    int pos=0;
    root = insertNode(v,root,lower,upper,pos);
    int sum=0;
    modify(root,sum);
    printpreorder(root);
}

// class Solution {
// public:
//      int i = 0;
//     TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
//         if (i == A.size() || A[i] > bound) return NULL;
//         TreeNode* root = new TreeNode(A[i++]);
//         root->left = bstFromPreorder(A, root->val);
//         root->right = bstFromPreorder(A, bound);
//         return root;
//     }
// };
