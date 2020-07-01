class Solution {
class node
{
public:
    char c;
    node *child[26];
    bool tail;
    string w;
    node(char d)
    {
        c = d;
        tail = false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
        w="";
    }
};
void dfs(vector<vector<char>>&board,int i,int j,int n,int m,vector<string>&ans,node *root)
{
    int index = board[i][j]-'a';
    
    if(board[i][j]=='$' || root->child[index]==NULL)
        return;
    
    root = root->child[index];
    
    if(root->tail == true)
    {
      ans.push_back(root->w);
      root->tail = false;
    }
    char ch = board[i][j];
    board[i][j]='$';

    if(i>0)   dfs(board,i-1,j,n,m,ans,root);
    if(i<n-1) dfs(board,i+1,j,n,m,ans,root);
    if(j>0)   dfs(board,i,j-1,n,m,ans,root);
    if(j<m-1) dfs(board,i,j+1,n,m,ans,root);
    
    board[i][j] = ch;
}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    
        node *root = new node('\0');
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            node *p = root;
            for(int j=0;s[j];j++)
            {
                int index = s[j]-'a';
                if(p->child[index]==NULL)
                {
                    node *t = new node(index);
                    p->child[index]=t;
                    p=t;
                }
                else
                {
                    p = p->child[index];
                }
            }
            p->tail = true;
            p->w = s;
        }
        int n = board.size();
        int m = board[0].size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dfs(board,i,j,n,m,ans,root);
            }
        }
        return ans;
    }
};
