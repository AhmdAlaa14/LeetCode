class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx=-1;
        int n= nums.size();
        int l=0,r= n-1,m;
        while(r>l){
            m=(l+r)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }else{
                r=m;
            }
        }
        int pivot = l;
        r=n-1;
        l=0;
        if(target>=nums[pivot]&&target<=nums[r]){
            l=pivot;
        }else{
            r=pivot;
        }
        while(r>=l){
            m = (r+l)/2;
            if(nums[m]==target){
                return m;
            }
            if(target>nums[m]){
                l=m+1;
            }else{
                r=m-1;
            }
        }

        return -1;
    }
};