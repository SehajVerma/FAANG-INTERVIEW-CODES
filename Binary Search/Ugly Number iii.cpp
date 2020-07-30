class Solution {
     long gcd(long a,long b)
     {
         if(b==0)
             return a;
         else
             return gcd(b,a%b);
     }
     long lcm(long a,long b)
     {
         return a*b/gcd(a,b);
     }
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        int low = 1;
        int high = 2 * (1e9);
        long a = long(A);
        long b = long(B);
        long c = long(C);
        long ab = lcm(a,b);
        long bc = lcm(b,c);
        long ac = lcm(a,c);
        long abc = lcm(a,bc);
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            
            if(cnt < n)
                low=mid+1;
            else
                high = mid;
        }
        return low;
    }
};
