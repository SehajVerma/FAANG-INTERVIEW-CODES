#include <bits/stdc++.h>
using namespace std;
int main() {
    int row,col;
    cin>>row>>col;
    int k=0;
    for(int i=1;i<=row;i++)
    {

        int x = ceil(float(row)/2.0);
        i<=x? k++ : k--;
        for(int j=1;j<=col;j++)
        {
            if(j>=x-k+1 && j<=x+k-1)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
