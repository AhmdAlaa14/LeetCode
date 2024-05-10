class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 == 1 || s[0]=='}' || s[0]==']' || s[0]==')'  ){
            return false;
        }
        stack<char> par;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                par.push(s[i]);
            }else if(s[i]=='}'){
                if(par.empty()){
                    return false;
                }
                if(par.top() != '{'){
                    return false;
                }else{
                    par.pop();
                }
            }else if(s[i]==')'){
                if(par.empty()){
                    return false;
                }
                if(par.top() != '('){
                    return false;
                }else{
                    par.pop();
                }
            }else if(s[i]==']'){
                if(par.empty()){
                    return false;
                }
                if(par.top() != '['){
                    return false;
                }else{
                    par.pop();
                }
            }
        }
        if(par.empty() == false){
            return false;
        }
        return true;
    }
};