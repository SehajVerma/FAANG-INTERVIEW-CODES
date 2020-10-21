vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int>a(A);
    vector<int>v;
    
    int miss=0,repeat=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[abs(a[i])-1]>0)
        {
            a[abs(a[i])-1] = -a[abs(a[i])-1];
        }
        else
        {
            repeat = abs(a[i]);
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>0)
        {
            miss = i+1;
            break;
        }
    }
    v.push_back(repeat);
    v.push_back(miss);
    return v;
}
