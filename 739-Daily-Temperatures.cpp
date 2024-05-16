class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> temp;
        for (int i = 0; i < temperatures.size() - 1; i++) {
            if (temperatures[i + 1] > temperatures[i]) {
                result[i] = 1;
            }
            while ((!temp.empty())&&temperatures[i] > temperatures[temp.top()]) {
                result[temp.top()] = i - temp.top();
                temp.pop();
            }
            if(!(temperatures[i + 1] > temperatures[i])) {
                temp.push(i);
            }
        }
        while ((!temp.empty())&&temperatures.back() > temperatures[temp.top()]) {
                result[temp.top()] = temperatures.size()-1 - temp.top();
                temp.pop();
            }
        return result;
    }
};