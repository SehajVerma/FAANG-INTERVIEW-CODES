void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
    int i=0,j=0;
    int ni=0;
    int nj=nCols;
    char dir = 'r';
    while(ni<=nRows/2 && nj>=(nCols-1)/2)
    {  
      while(j<nj && dir=='r')
      {
        cout<<input[i][j]<<" ";
        j++;
      }
        dir='d';
        j--; 
        i++;
      while(i<(nRows-ni) && dir=='d')
      {
        cout<<input[i][j]<<" ";
        i++;
      }
        dir='l';
        i--;
        j--;
      while(j>=(nCols-nj) && dir=='l')
      {
        cout<<input[i][j]<<" ";
        j--;
      }
        dir='u';
        j++;
        i--;
      while(i>ni && dir=='u')
      {
        cout<<input[i][j]<<" ";
        i--;
      }
        dir='r';
        i++;
        j++;
        ni++;
        nj--;
    }
}


//
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int T,B,L,R,dir;
    T=0;
    B=A.size()-1;
    L=0;
    R=A[0].size()-1;
    dir=0;
    int i;
    vector<int> ans;
    
    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(i=L;i<=R;i++)
                ans.push_back(A[T][i]);
            T++;
        }
        else if(dir==1)
        {
            for(i=T;i<=B;i++)
                ans.push_back(A[i][R]);
            R--;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--)
                ans.push_back(A[B][i]);
            B--;
        }
        else if(dir==3)
        {
            for(i=B;i>=T;i--)
                ans.push_back(A[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}
