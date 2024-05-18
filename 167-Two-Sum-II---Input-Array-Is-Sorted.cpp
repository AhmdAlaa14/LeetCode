class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,-1);
        int size=numbers.size();
        int l=0;
        int r=size-1;
        while(l<r){
            int sum = numbers[r]+numbers[l];
            if(sum==target){
                result[0]=l+1;
                result[1]=r+1;
                break;
            }else if(sum>target){
                r--;
            }else{
                l++;
            }
        }
        return result;
    }
};