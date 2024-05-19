class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l = i+1, r = size - 1;
            if(nums[i]>0){
                break;
            }else if (nums[i]+nums[l]>0){
                break;
            }
            while (l < r) {
                if (nums[i]+nums[l]>0){
                    break;
                }
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> temp{nums[i], nums[l], nums[r]};
                    result.emplace_back(temp);
                    l++;
                    while( l<r&&nums[l]==nums[l-1] ){
                        l++;
                    }
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return result;
    }
};