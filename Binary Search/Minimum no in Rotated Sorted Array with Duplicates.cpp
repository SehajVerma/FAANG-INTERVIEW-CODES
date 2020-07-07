https://leetcode.com/explore/learn/card/binary-search/144/more-practices/1031/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        while(low<high)
        {
           int mid = (low+high)/2;
           if(nums[mid]>nums[high])
               low=mid+1;
            else if(nums[mid]<nums[high])
                high=mid;
            else
                high--;
        }
        return nums[low];
    }
};
