https://discuss.codechef.com/t/need-help-in-a-problem/77896

The Teacher wants to divide the group of students for singing competition . Each group will have one mic . If the number of mic is greater than the number of groups then teacher can select group and divide it such that the largest group among all groups is as small as possible .
Test case 1 :
n = 5 , k =7 ; k is number of groups mics and n is number of groups initially
[10 , 8 , 6 , 3 ,2 ] – > initially number of students in each group .
Output = 6 ;
we can divide the group of 10 into 5 ,5 —> [5,5, 8 ,6 ,3, 2]
again we divide the group of 8 into 4, 4 – > [5 ,5 , 4 ,4 ,6,3 ,2]
The numbers of groups equals to the number of mics Hence the largest group is of size 6 .

Test case 2 :
n = 5 ,k =9
[100 , 80 , 60 ,40 , 30] – > initially number of students in each group .
Output = 40
First divide the group of 100 into 80 , 20 – > [80 ,20 ,80 , 60 , 40 ,30]
Now divide the group of 80 into 40 ,40 --> [40 , 40 , 20 , 80 , 60 ,40 ,30]
again divide the group of 80 into 40, 40 – > [40 , 40 ,20 ,40 ,40 ,60 ,40 ,30]
divide the group of 60 into 30 ,30 --> [40, 40 , 20 , 40 ,40 , 30 ,30 ,40 ,30]
The numbers of groups equals to the number of mics Hence the largest group is of size 40 .





#include<bits/stdc++.h>
#define int long long
using namespace std ;

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL) ;

int n , k  ;
cin >> n >> k  ; 
vector<int> a(n) ; 
for(int i = 0; i < n ; ++i)
	cin >> a[i] ; 
int lo = 1, hi = 1e10 ; 
while(lo < hi)
{
	int mid = (lo + hi)/2  , r = 0 ; 
	for(int i = 0 ; i < n ; ++i)
	{
		r += ceil((double)a[i]/mid) ; 
	}

	if(r <= k)
	{
		hi= mid ;
	}
	else 	
		lo = mid +1 ; 
	
}
cout << hi ; 
}
