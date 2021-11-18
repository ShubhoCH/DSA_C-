//Time:  O(N);
//Space: O(N);
const int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++){
            string key = words[i];
            reverse(key.begin(), key.end()); // mirror 
            m[key] = i;
        }
        
        for(int i = 0; i < n; i++){
            if(m.count("") && m[""] != i && isPalindrom(words[i]))
                res.push_back({i, m[""]});
            
            for(int j = 1; j <= words[i].size(); j++){
                const string left = words[i].substr(0, j);
                const string right = words[i].substr(j);
                if(m.count(left) && m[left] != i && isPalindrom(right) )
                    res.push_back({i, m[left]});
                
                if(m.count(right) && m[right] != i && isPalindrom(left) )
                    res.push_back({m[right], i});
            }
        }
        return res;
    }
    
private:
    bool isPalindrom(const string& s){
        for(int l = 0, r = s.size() - 1; l < r; )
            if(s[l++] != s[r--]) return false;
        return true;
    }
