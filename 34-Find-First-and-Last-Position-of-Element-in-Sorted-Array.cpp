class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){
                return {0,0};
            }else{
                return {-1,-1};
            }
        }
        vector<int> result{-1,-1};
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[r]!=target){
                r--;
            }
            if(nums[l]!=target){
                l++;
            }
            if(nums[l]==target && nums[r]==target){
                result[0]=l;
                result[1]=r;
                break;
            }
        }
    return result;
    }
};