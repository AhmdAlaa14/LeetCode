class Solution {
public:

    void checkValid(vector<string>&result,string str,int open,int closed,int n) {
        if (open == n && closed == n) {
            result.emplace_back(str);
        }else if(open>=closed){
            checkValid(result, str + ')', open, closed + 1, n);
            if (open != n) {
                checkValid(result, str + '(', open + 1, closed, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        checkValid(result,"",0,0,n);
        return result;
    }
};