#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map<char,int>m;
    for(int i=0;s[i];i++)
     m[s[i]]=i;
    map<char,bool>mt;
    stack<char>st;
    for(int i=0;s[i];i++)
    {
        if(mt[s[i]]==true)
         continue;
        while(!st.empty() && s[i]<st.top() && m[st.top()]>i)
            {
                mt[st.top()]=false;
                st.pop();
            }
                st.push(s[i]);
                mt[s[i]]=true;
    }
    string output;
    while(!st.empty())
    {
        output+=st.top();
        st.pop();
    }
    reverse(output.begin(),output.end());
    cout<<output<<endl;
}
