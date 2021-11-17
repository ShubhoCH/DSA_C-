//Time:  O(N+E);
//Space: O(N+E) + O(N) + O(N);
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> visited(V+1, false);
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto it: adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = true;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};
