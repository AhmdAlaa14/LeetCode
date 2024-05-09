class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        int currentMax =1;
        int max=1;
        set<int> sortedNums;
        for(int x:nums){
            sortedNums.emplace(x);
        }
        
        auto prevIt = sortedNums.begin();
        auto it = prevIt;
        it++;
        for(; it != sortedNums.end() ;it++,prevIt++){
            if(*it == *prevIt + 1){
                currentMax++;
            }else{
                if(currentMax>max){
                    max=currentMax;
                }
                currentMax = 1;
            }
        }
        if (currentMax > max) {
            max = currentMax;
        }
        return max;
    }
};