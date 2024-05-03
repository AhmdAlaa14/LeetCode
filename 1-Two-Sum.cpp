class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2);
        bool flag=false;
        for(int i=0;i<nums.size()-1;i++){
            for(int j =i+1;j<nums.size();j++){
                int med = nums[i]+nums[j];
                if(med<target){
                    continue;
                }else if(med == target){
                    result[0] = i ;
                    result[1] = j ;
                    flag= true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return result;
    }
};