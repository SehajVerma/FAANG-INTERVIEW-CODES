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


//more solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root && !subroot) return true;
        
        if(!root) return false;
        
        if(answer(root, subroot))
                return true;
        
        return isSubtree(root->left, subroot) ||
                isSubtree(root->right, subroot);
    }
    
    bool answer(TreeNode* root, TreeNode* subroot)
    {
        if(!root && !subroot) return true;
        if(!root || !subroot) return false;
        
        if(root->val != subroot->val)
            return false;
        
        return answer(root->left, subroot->left) && 
                    answer(root->right, subroot->right);
    }
};
