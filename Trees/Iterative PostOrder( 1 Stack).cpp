class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<pair<TreeNode*,int>>s;
        s.push({root,0});
        while(!s.empty())
        {
            auto t = s.top();
            TreeNode* cur = t.first;
            int state = t.second;
            
            s.pop();
            
            if(cur==NULL || state == 3) continue;
            
            s.push({cur,state+1});
            
            if(state == 0 ) s.push({cur->left,0});
            else if(state == 1) s.push({cur->right,0});
            else if(state == 2) v.push_back(cur->val);
            
        }
        return v; 
    }
};
