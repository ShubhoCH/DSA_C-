//Time:  O(N);
//Space: O(N);
class Solution {
   public:
   int leastInterval(vector<char>& t, int n) {
      map <char,int> m;
      for(int i =0;i<t.size();i++){
         m[t[i]]++;
      }
      map <char, int> :: iterator i = m.begin();
      priority_queue <int> pq;
      while(i != m.end()){
         pq.push(i->second);
         i++;
      }
      int ans = 0;
      int cycle = n + 1;
      while(!pq.empty()){
         vector <int> temp;
         int time = 0;
         for(int i = 0; !pq.empty() && i < cycle; i++){
            temp.push_back(pq.top());
            pq.pop();
            time++;
         }
         for(int i = 0;i < temp.size(); i++){
            temp[i]-- ;
            if(temp[i]) 
                pq.push(temp[i]);
         }
         ans += pq.empty()? time : cycle;
      }
      return ans;
   }
};
