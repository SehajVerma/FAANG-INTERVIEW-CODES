int solve(Node* root,bool &ans) {
    if(root==NULL) return 0;
    
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    
    if(abs(l-r)>1)
        ans = 0;
    return max(l,r)+1;
}

bool isBalanced(Node *root)
{
    bool ans=1;
    solve(root,ans);
    return ans;
}
