class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<int> result;
        for (auto x : nums) {
            if (mp.count(x) == 0) {
                mp[x] = 1;
            }
            else {
                mp[x]++;
            }
        }
        std::multimap<int, int> mmp;
        for (auto x : mp) {
            mmp.insert({ x.second, x.first });
        }
        auto it = mmp.rbegin();
        
        for (int i = 0; i < k; i++) {
            result.emplace_back(it->second);
            it++;
        }
        
        return result;
    }
};