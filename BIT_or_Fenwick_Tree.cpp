#include <bits/stdc++.h>
using namespace std;

void update(int BIT[], int n, int i, int val){
    for(; i <= n; i += (i&-i)){
        BIT[i] += val;
    }
}

int query(int BIT[], int i){
    int sum = 0;
    for(; i > 0; i -= (i&-i)){
        sum += BIT[i];
    }
    return sum;
}

void Convert(int arr[], int n){
    int temp[n];
    for(int i = 0; i < n; i++){temp[i] = arr[i];}
    sort(temp, temp+n);
    
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}

int getCount(int arr[], int n){
    Convert(arr, n);
    
    int BIT[n+1] = {0};
    int greater1[n] = {0}; int greater2[n] = {0};
    
    for(int i = n-1; i >= 0; i--){
        greater1[i] = (n-i-1)-query(BIT, arr[i]-1);
        update(BIT, n, arr[i], 1);
    }
    
    for(int i = 0; i <= n; i++){BIT[i] = 0;}
    
    for(int i = 0; i < n; i++){
        greater2[i] = query(BIT, arr[i]-1);
        update(BIT, n, arr[i], 1);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        count += greater2[i]*greater1[i];
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){cin>>arr[i];}
        cout<<getCount(arr, n)<<endl;
    }
	return 0;
}
