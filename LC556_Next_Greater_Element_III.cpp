//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int sz = s.size();
        int i;
        bool ok = false;
        for(i = sz - 2; i >= 0; i--){
         if(s[i] < s[i + 1]) {
            ok = true;
            break;
         }
        }
        if(!ok) return -1;
        int smallest = i;
        int curr = i + 1;
        for(int j = i + 1; j < sz; j++){
         if(s[j] > s[smallest] && s[j] <= s[curr]){
            curr = j;
         }
        }
        swap(s[smallest], s[curr]);
        string aux = s.substr(smallest + 1);
        reverse(aux.begin(), aux.end());
        string ret = s.substr(0, smallest + 1) + aux;
        return stol(ret) > INT_MAX ? -1 : stol(ret);
   }
};
