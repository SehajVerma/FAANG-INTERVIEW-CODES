#
Explanation - https://www.youtube.com/watch?v=Ss9ta1zmiZo

bool isValidConf(vector<int>&A,int B,int n,int mid)
{
    int no_of_students=1;
    int pages=0;
    for(int i=0;i<n;i++)
    {
        if(pages+A[i]>mid)
        {
           no_of_students++;
           pages=A[i];
           if(no_of_students>B)
           return false;
        }
        else
          pages+=A[i];
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
    return -1;
    if(A.size()==B)
    return *max_element(A.begin(),A.end());
    int low=0;
    int sum=0;
    for(int i=0;i<A.size();i++){
    sum+=A[i];
    low=max(low,A[i]);
    }
    int high=sum;
    
    int finalAns=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isValidConf(A,B,A.size(),mid))
        {
            finalAns=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return finalAns;
}
