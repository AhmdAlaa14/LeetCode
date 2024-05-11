class MinStack {
private:
    vector<pair<int,int>> vec;                 /*first is the value second is the min so far*/
public:
    MinStack()=default;
    
    void push(int val) {
        if(vec.size()==0){
            vec.emplace_back(val,val);
        }else{
            if(val<vec[vec.size()-1].second){
                vec.emplace_back(val,val);
            }else{
                vec.emplace_back(val,vec[vec.size()-1].second);
            }
        }
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back().first;
    }
    
    int getMin() {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */