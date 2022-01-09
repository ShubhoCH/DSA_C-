//Time:  O(26*N*N*W[No. of Words]);
//Space: O(N);
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool isPresent = false;
        for(auto x: wordList){
            s.insert(x);
            if(x==endWord)
                isPresent = true;
        }
        if(!isPresent)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c = 'a';c<='z';c++){
                        temp[i] = c;
                        if(temp == curr)
                            continue;
                        if(temp == endWord) return depth+1;
                        if(s.find(temp) != s.end()){
                            s.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
