class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int>result(2);
        for(int i=0;i<nums.size();i++){
            int complementary = target - nums[i];
            if(mp.count(complementary) == 1 ){
                result[0]=i;
                result[1]= mp[complementary];
                break;
            }else{
                mp.emplace(nums[i],i);
            }
        }
        return result;
    }
};