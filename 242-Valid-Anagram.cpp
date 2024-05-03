class Solution {
public:
    bool isAnagram(string s, string t) {
        bool result = true;
        int sChars[26]{0};
        int tChars[26]{0};
        for(int i=0;s[i];i++){
            sChars[s[i]-'a']++;
        }
        for(int i=0;t[i];i++){
            tChars[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(sChars[i]!=tChars[i]){
                result = false;
            }else{
                
            }
        }
        return result;
    }
};