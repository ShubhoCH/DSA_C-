//Time:  O(N) + O(N) + O(N);
//Space: O(N);
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int, bool> m;
        int len =0, maxLen = 0,temp = 0, n = arr.size();
        if(arr.empty()) return 0;
        for(int i=0; i<n;i++) m[arr[i]] = false;
        for(int i=0; i<n; i++){
            temp = arr[i];
            if(m[temp] == true) continue;
            len = 0;
            while(m.find(temp) != m.end()) {
                len++;
                m[temp] = true;
                ++temp;
            }
            temp = arr[i]-1;
            while(m.find(temp) != m.end()){
                len++;
                m[temp] = true;
                --temp;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
