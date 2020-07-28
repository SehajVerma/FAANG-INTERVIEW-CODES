class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left,p,q);
        TreeNode *r = lowestCommonAncestor(root->right,p,q);
        
        if(l&& r&& ((l->val==p->val && r->val==q->val) || (l->val==q->val && r->val==p->val)))
            return root;
        
        if(l==NULL) return r;
        else return l;
    }
};
