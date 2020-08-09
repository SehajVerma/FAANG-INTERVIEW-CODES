class Solution {
public:
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i==j)
                    break;
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
