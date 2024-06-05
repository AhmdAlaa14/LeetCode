class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1 || s.length() == 0) {
            return s.length();
        }
        int l = 0, r = 0;
        int max = r - l + 1;
        map<char, int> mp;
        mp.emplace(s[0], 0);
        for (int i = 1; i < s.length(); i++) {
            if (mp.count(s[i]) < 1) {
                r++;
                mp.emplace(s[i], i);
            } else {
                if (mp[s[i]] >= l) {
                    if (r - l + 1 > max) {
                        max = r - l + 1;
                    }
                    l = mp[s[i]] + 1;
                    mp[s[i]] = i;
                    r++;
                } else {
                    r++;
                    mp[s[i]] = i;
                }
            }
        }
        if (r - l + 1 > max) {
            max = r - l + 1;
        }
        return max;
    }
};