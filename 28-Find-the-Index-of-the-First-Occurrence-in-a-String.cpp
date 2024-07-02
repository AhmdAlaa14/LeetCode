class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length()+1; i++) {
            for (int j = 0; j < needle.length(); j++) {
                if (needle[j] == haystack[i + j]) {
                    if (j == needle.length() - 1) {
                        return i;
                    }
                    continue;
                }
                else {
                    break;
                }
            }
        }
        return -1;
    }
};