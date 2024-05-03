class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<unsigned char> zeros(nums.size(),0) ;
        map<int, unsigned char> counts;
        bool result = false;
        for (int& x : nums) {
            if (counts.find(x) == counts.end()) {
                counts.insert({ x,1 });
            }
            else {
                result= true;
                break;
            }
        }
        return result;
    }
};