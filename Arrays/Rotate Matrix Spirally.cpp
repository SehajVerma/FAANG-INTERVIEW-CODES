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
