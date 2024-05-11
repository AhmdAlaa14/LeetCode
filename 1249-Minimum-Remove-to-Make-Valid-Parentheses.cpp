class Solution {
public:
    string minRemoveToMakeValid(string s) {
    string result;
    stack<int> par;
    vector<bool> val(s.length(),false);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            par.push(i);
        }
        else if (s[i] == ')') {
            if (par.empty()) {
                continue;
            }
            else {
                if (i > val.size()) {
                    cout << i;
                }
                else if (i > par.top()) {

                }
                val[i]=true;
                val[par.top()]=true;
                par.pop();
            }
        }
        else {
            val[i] = true;
        }
    }
    /*Now val should include the indices of all the valid parentheses*/
    for (int i = 0; i < s.length(); i++) {
        if (val[i]) {
            result += s[i];
        }
    }
    return result;
}
};