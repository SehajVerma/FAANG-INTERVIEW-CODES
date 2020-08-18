vector<int> Solution::flip(string A) {
    int count=0;
    int l=-1,r=-1,ltemp=0;
    int max_count=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='0')
        count++;
        else
        count--;
        if(count<0)
        {
          count=0;
          ltemp=i+1;
        }
        else if(count>max_count)
        {
            max_count=count;
            l=ltemp;
            r=i;
        }
    }
    vector<int>v;
    if(l==-1 && r==-1)
    return v;
    
    v.push_back(l+1);
    v.push_back(r+1);
    return v;
}
