class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> nodes(n);
        vector<bool> visited(n,false);
        for(auto edge:edges){
            nodes[edge[0]].emplace_back(edge[1]);
            nodes[edge[1]].emplace_back(edge[0]);
        }
        return dfs(nodes,source,destination,visited);
    }

    bool dfs(vector<vector<int>>& nodes ,int source,int destination,vector<bool>& visited){
        visited[source]=true;
        bool result=false;
        if(source == destination){
            return true;
        }
        for(int i=0;i<nodes[source].size();i++){
            if(visited[nodes[source][i]]==false){
                result |= dfs(nodes,nodes[source][i],destination,visited);
                if(result == true){
                    return result;
                }
            }
        }
        return result;
    }
};