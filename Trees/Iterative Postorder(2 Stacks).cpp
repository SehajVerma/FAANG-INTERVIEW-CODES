class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s2.push(root);
        while(1)
        {
            TreeNode *p = s2.top();
            if(p->left!=NULL) s1.push(p->left);
            if(p->right!=NULL) s1.push(p->right);
            if(s1.empty()) break;
            TreeNode *r = s1.top();
            s1.pop();
            s2.push(r);
            
        }
        while(!s2.empty())
        {
            TreeNode* p = s2.top();
            s2.pop();
            v.push_back(p->val);
        }
        return v;
    }
};
