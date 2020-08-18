class Solution {
public:
    bool isSame(TreeNode* s,TreeNode* t)
    {
        if(t==NULL && s==NULL)
            return true;
        if(t==NULL || s==NULL)
            return false;
        if(s->val==t->val)
          return isSame(s->left,t->left) && isSame(s->right,t->right);
        else
            return false;
    }
    bool solve(TreeNode* s, TreeNode* t)
    {
        if(!s)
            return false;
        return isSame(s,t) || solve(s->left,t) || solve(s->right,t);
    }
    int cnt=0;
    void inorder(TreeNode* s)
    {
        if(s==NULL)
            return;
        inorder(s->left);
        cnt++;
        inorder(s->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(solve(s,t))
        {
            inorder(t); 
            cout<<cnt;
            return true;
        }
        else
            return false;
        
    }
};
