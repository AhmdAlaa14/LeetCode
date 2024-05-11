class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> tokens;
        string token;
        while(getline(iss,token,'/')){
            tokens.emplace_back(token);
        }
        stack<string> dirs;
        for(auto tok:tokens){
            if(tok == "."){
                continue;
            }else if (tok == ".." ){
                if(!dirs.empty()){
                    dirs.pop();
                }
            }else if (tok !=""){
                dirs.push(tok);
            }
        }
        tokens.clear();
        tokens.shrink_to_fit();
        if(dirs.empty()){
            return "/";
        }
        token = "";
        while(!dirs.empty()){
            token = "/" + dirs.top() +token;
            dirs.pop();
        }
        return token;
    }
};