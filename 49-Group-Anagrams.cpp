class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*To hold the characters of the anagram in first and the strings that are anagrams in second*/
        unordered_map<string,vector<string>> mp;
        for(auto it:strs){
            /*Sorting the string to get the key*/
            string temp = it;   
            sort(temp.begin(),temp.end());
            /*Adding the string to the anagrams list*/
            mp[temp].emplace_back(it);
        }
        vector<vector<string>> result;
        for(auto it:mp){
            /*Cutting the anagrams from the map*/
            result.emplace_back(it.second);
        }
        /*Clearing the map*/
        mp.clear();
        return result;
    }
};