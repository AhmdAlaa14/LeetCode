class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,m=0;
        int min=INT_MAX;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]<=nums[r]){
                if(nums[m]<min){
                    min=nums[m];
                }
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return min;
    }
};