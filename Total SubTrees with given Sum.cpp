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
vector<int>v;
char s[1000];
void StringtoInt()
{
    char *ptr;
    ptr=strtok(s," ");
    while(ptr!=NULL)
    {
        v.push_back(stoi(ptr));
        ptr = strtok(NULL," ");
    }
}
int sum(node *root)
{
    if(root==NULL)
    return 0;
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return leftsum + rightsum + root->data;
}
int count(node *root,int x)
{
    if(root==NULL)
    return 0;

    int ans=0;
    if(sum(root)==x)
    ans=1;

    int left_sum = count(root->left,x);
    int right_sum = count(root->right,x);
    return ans+left_sum+right_sum;
}
node *createTree()
{
    if(strlen(s) ==0 || v.size()==0) return NULL;
    int i=1;
    node *root=new node(v[0]);
    queue<node*>q;
    q.push(root);
    while(!q.empty() && i<v.size())
    {
        node *n = q.front();
        q.pop();
        //if(i<v.size()){
        n->left=new node(v[i++]);
        q.push(n->left);
        if(i>=v.size())
        break;
        //}

        //if(i<v.size()){
        n->right=new node(v[i++]);
        q.push(n->right);
        if(i>=v.size())
        break;
        //}
    }
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
    int t;
    cin>>t;
    while(t--)
    {
        cin.ignore();
        cin.getline(s,1000);
        int x;
        cin>>x;
        StringtoInt();

        node *root = createTree();
        //inorder(root);
        cout<<count(root,x)<<endl;
    }
}
