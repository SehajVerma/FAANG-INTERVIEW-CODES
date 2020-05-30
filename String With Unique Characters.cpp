#include <bits/stdc++.h>
using namespace std;
int UniqueChar(vector<string>&arr,int i,string s)
{
    if(i==arr.size())
    {
        if(s.length()>26) return  0;
        int freq[26]={0};
        for(int k=0;k<s.length();k++)
        {
            if(freq[s[k]-'a']==1) return 0;

            freq[s[k]-'a']++;
        }
        return s.length();
    }

     int op1;
     int op2;
     op1=op2=INT_MIN;

     if(s.length()+arr[i].length()<=26)
     {

         op1= UniqueChar(arr,i+1,s+arr[i]);
     }
     op2=UniqueChar(arr,i+1,s);

     return max(op1,op2);
}
int main()
{
    int n;
    cin>>n;
    vector<string>arr;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr.push_back(s);
    }
    string s="";
    cout<<UniqueChar(arr,0,s);
}
