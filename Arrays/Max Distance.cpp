https://www.interviewbit.com/problems/max-distance/
Interview Bit
O(nlogn)

bool comp(pair<int,int>& p1 , pair<int,int>& p2)
{
    return p1.first<p2.first;
}
int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==1)
    return 0;
    vector<pair<int,int>>v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back({A[i],i});
    }
    sort(v.begin(),v.end(),comp);
    
    int max_index=v[A.size()-1].second;
    int ans=0;
    for(int i=A.size()-2;i>=0;i--)
    {
       if(max_index-v[i].second >= 0)
       {
           ans=max(ans,max_index-v[i].second);
       }
       max_index=max(max_index,v[i].second);
    }
    return ans;
}
