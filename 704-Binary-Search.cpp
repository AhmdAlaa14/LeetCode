class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) {
            return 0;
        }
        int r = nums.size() - 1, l = 0;
        int mid = (r + l) / 2;
        while (r > l) {
            mid=(l+r)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }
        if(nums[l]==target){
            return l;
        }
        return -1;
    }
};