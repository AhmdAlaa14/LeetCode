class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp{
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
        };
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }
        for (unsigned int i = 0; i < mp[digits[0]].size(); i++) {
            result.emplace_back(string() + mp[digits[0]][i]);
        }
        for (unsigned int i = 1; i < digits.length(); i++) {
            for (unsigned int j = 0; j < result.size(); j++) {
                for (unsigned int k = 0; k < mp[digits[i]].size(); k++) {
                    result.emplace( result.begin() + j + 1, result[j] + mp[digits[i]][k]);
                }
                result.erase(result.begin()+j);
                j += mp[digits[i]].size() - 1;
            }
        }
        return result;
    }
};
