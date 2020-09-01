https://www.interviewbit.com/problems/longest-substring-without-repeat/
O(n)

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int>m;
    int start=0,end=0,maxlen=INT_MIN;
    if(A.length()==1) return 1;
    
    while(end<A.size())
    {
        m[A[end]]++;
        while(m[A[end]]>1)
        {
            m[A[start]]--;
            start++;
        }
        end++;
        maxlen = max(maxlen,end-start);
    }
    return maxlen;
}
