#include <bits/stdc++.h>
using namespace std;
string compress(string message)
{
    int i=0,j=1;
    //string s;
    int k=0;
    int n=message.size();
    while(i<n)
    {
        message[k++]=message[i];
        while(j<n && message[i]==message[j])
        j++;

        int l=j-i;
        if(l!=1){
        string c=to_string(l);
        for(auto m:c)
        message[k++]=m;
        }
        i=j;
        j++;
    }
    return message.substr(0,k);
}
int main() {
    string message;
    cin>>message;
    cout<<compress(message);
}
