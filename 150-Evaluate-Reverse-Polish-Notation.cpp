class Solution {
public:
    int evaluateOperation(int a , int b , string op){
        if(op=="+")return a+b;
        if(op=="-")return a-b;
        if(op=="*")return a*b;
        if(op=="/")return a/b;
        return -1;
    }
    bool isOperand(string op ){
        if(op=="+")return true;
        if(op=="-")return true;
        if(op=="*")return true;
        if(op=="/")return true;
        return false;
    } 
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0){
            return 0;
        }else if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        stack<int> operands;
        for(string token:tokens){
            if(isOperand(token)){
                int num1=operands.top();
                operands.pop();
                int num2=operands.top();
                operands.pop();
                operands.push(evaluateOperation(num2,num1,token));
            }else{
                operands.push(stoi(token));
            }
        }
    int result=operands.top();
    operands.pop();
    return result;
    }
};