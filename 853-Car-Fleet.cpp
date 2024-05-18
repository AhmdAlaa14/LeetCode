class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result=1;
        map<int,int> mp;
        stack<float>fleets;
        for(int i=0;i<position.size();i++){
            mp.emplace(position[i],speed[i]);
        }
        auto it = mp.rbegin();
        fleets.push((target-static_cast<float>(it->first))/it->second);
        it++;
        while(it != mp.rend()){
            float t2 = (target-static_cast<float>(it->first))/it->second;
            if(fleets.top()<t2){
                fleets.push(t2);
                result++;
            }
            it++;
        }
        return result;
    }
};