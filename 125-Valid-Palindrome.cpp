class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        char diff='a'-'A';
        for(char c:s){
            if((c>='a' && c<='z')||(c>='0'&&c<='9')){
                s2+=c;
            }else if(c>='A'&&c<='Z'){
                s2+=(c+diff);
            }
        }
        int len=s2.length();
        for(int i=0;i<len/2;i++){
            if(s2[i]!=s2[len-i-1]){
                return false;
            }
        }
        return true;
    }
};