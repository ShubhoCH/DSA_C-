//Time:  O(N);
class LockingTree {
    vector<int> L,P;
    vector<vector<int>> D;
public:
    LockingTree(vector<int>& parent) {
        int n=parent.size();
        P=parent;
        D= vector<vector<int>> (n);
        for(int i=1;i<n;i++){
            D[parent[i]].push_back(i);
        }
        
        L=vector<int> (n,0);
        
    }
    
    bool lock(int num, int user) {
        if(L[num]!=0) return false;
        L[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(L[num]!=user) return false;
        L[num]=0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        int x=num;
        while(x!=-1){
            if(L[x]!=0) return false;
            x=P[x];
        }
        vector<int> LD;
        stack<int> S;
        S.push(num);
        while(!S.empty()){
            int T=S.top();
            S.pop();
            if(L[T]!=0){
                LD.push_back(T);
            }
            for(int i=0;i<D[T].size();i++){
                S.push(D[T][i]);
            }
        }
        if(LD.size()==0) return false;
        L[num]=user;
        for(int i=0;i<LD.size();i++)
            L[LD[i]]=0;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
