class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size());
        vector<int>prefix(nums.size());
        vector<int>postfix(nums.size());
        prefix[0]=1;
        postfix[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]*nums[i-1];
            postfix[nums.size()-1-i] = postfix[nums.size()-i]* nums[nums.size()-i]; 
        }
        for(int i=0;i<nums.size();i++){
            result[i]=postfix[i]*prefix[i];
        }
        return result;
    }
};