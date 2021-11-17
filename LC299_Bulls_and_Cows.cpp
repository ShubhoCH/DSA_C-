//Time:  O(N);
//Space: O(N^2);
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, vector<int>>map;
        unordered_map<char, int>map2;
        for(int i=0;i<secret.size();i++)
            map[secret[i]].push_back(i);
        int b=0, c=0;
        for(int i=0;i<guess.size();i++)
            if(map.find(guess[i]) != map.end()){
                bool found = false;
                for(int j =0;j<map[guess[i]].size();j++)
                    if(map[guess[i]][j] == i)
                        found = true;
                if(found){
                    b++;
                    map2[guess[i]]++;
                }
            }
        for(int i=0;i<guess.size();i++)
            if(map.find(guess[i]) != map.end()){
                if(map2[guess[i]] < map[guess[i]].size()){   
                    bool found = false;
                    for(int j =0;j<map[guess[i]].size();j++)
                        if(map[guess[i]][j] == i)
                            found = true;
                    if(!found){
                        c++;
                        map2[guess[i]]++;
                    }
                }
            }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};
