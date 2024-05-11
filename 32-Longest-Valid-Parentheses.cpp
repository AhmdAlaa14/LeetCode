class Solution {
public:
    int longestValidParentheses(string s) {
        int max=0;
        int currentMax=0;
        vector<bool>valid(s.length(),false);
        stack<int>validIndex;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                validIndex.push(i);
            }else if (s[i]==')'){
                if(validIndex.empty()){
                    continue;
                }else{
                    valid[i]=true;
                    valid[validIndex.top()]=true;
                    validIndex.pop();
                }
            }else{
                valid[i]=true;
            }
        }
        for(int i=0;i<valid.size();i++){
            if(valid[i]){
                currentMax++;
            }else{
                if(currentMax>max){
                    max=currentMax;
                }
                currentMax=0;
            }
        }
        if (currentMax > max) {
            max = currentMax;
        }
        return max;
    }
};