https://leetcode.com/explore/learn/card/binary-search/144/more-practices/1033/

class Solution {
    int solve(vector<int>&nums)
    {
        int n = nums.size();
        if(nums[0]<=nums[n-1])
            return nums[0];
        int low=0;
        int high=n-1;
        while(low<=high)
        {
           int mid = (low+high)/2;
           if(nums[mid]>nums[mid+1])
               return nums[mid+1];
           if(nums[mid]<nums[mid-1])
               return nums[mid];
           if(nums[mid]>nums[high])
               low=mid+1;
            else
                high=mid-1;
        }
        return 0;
    }
public:
    int findMin(vector<int>& nums) {
        return solve(nums);
    }
};
