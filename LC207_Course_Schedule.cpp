//Time:  O(N+E);
//Space: O(N+E) + O(N);
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<vector<int>> v(numCourses);
        for(int i=0;i<pr.size();i++)
            v[pr[i][0]].push_back(pr[i][1]);
        vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0)
                if(isCyclic(i,v,visited))
                    return false;
        }
        return true;
    }
    bool isCyclic(int curr, vector<vector<int>>& v, vector<int>& visited){
        if(visited[curr] == 2) return true;
        visited[curr] = 2;
        for(int i=0;i<v[curr].size();i++){
            if(visited[v[curr][i]] != 1)
                if(isCyclic(v[curr][i],v,visited))
                    return true;
        }
        visited[curr] = 1;
        return false;
    }
};

