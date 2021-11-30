//Time:  O(NlogN);
//Space: O(N);
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0, hi = (int)removable.size();
        auto is_valid = [&](int mid)->bool{
            string other1 = s;
            for(int i = 0; i < mid; i++) other1[removable[i]] = '0';
            string other2 = "";
            for(int i = 0; i < (int)other1.size(); i++) if(other1[i] != '0') other2 += other1[i];
            int j = 0;
            for(int i = 0; i < (int)other2.size(); i++) if(other2[i] == p[j]) j++;
            return (j == (int)p.size());
        };
        while(hi - lo > 1){
            int mid = (lo + (hi - lo) / 2);
            if(is_valid(mid)) lo = mid;
            else hi = mid;
        }
        return (is_valid(hi) ? hi : lo);
    }
};
