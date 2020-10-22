https://leetcode.com/problems/path-sum-iii/

class Solution {
    int c=0;
public:
    void solve(TreeNode* root,int sum,int temp,unordered_map<int,int>&mp)
    {
        if(root==NULL)
            return;
        temp+=root->val;
        if(mp.find(temp-sum)!=mp.end())
        {
            c+=mp[temp-sum];
        }
        mp[temp]++;
        solve(root->left,sum,temp,mp);
        solve(root->right,sum,temp,mp);
        mp[temp]--;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int>mp;
        mp.insert({0,1});
        solve(root,sum,0,mp);
        return c;
    }
};
