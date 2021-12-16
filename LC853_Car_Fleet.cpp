//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
          vector < pair <double, double> > v;
          int n = p.size();
          for(int i = 0; i < n; i++){
             v.push_back({p[i], s[i]});
          }
          int ret = n;
          sort(v.begin(), v.end());
          stack <double> st;
          for(int i = 0; i < n; i++){
             double temp = (t - v[i].first) / v[i].second;
             while(!st.empty() && st.top() <= temp){
                ret--;
                st.pop();
             }
             st.push(temp);
          }
          return ret;
    }
};
