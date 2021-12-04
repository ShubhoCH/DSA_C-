//Time:  O(N+E);
//Space: O(N+E) + O(N) + O(N);
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                if(!bipertiteDFS(i,graph,color))
                    return false;
            }
        }
        return true;
    }
    bool bipertiteDFS(int curr, vector<vector<int>>& graph, vector<int>& color){
        if(color[curr] == -1) 
            color[curr] = 1;
        for(auto it: graph[curr]){
            if(color[it] == -1){
                color[it] = 1 - color[curr];
                if(!bipertiteDFS(it,graph,color))
                    return false;
            }else if(color[it] == color[curr]) 
                return false;
        }
        return true;
    }
};
