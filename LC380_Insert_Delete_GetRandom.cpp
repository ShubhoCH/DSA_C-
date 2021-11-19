
class RandomizedSet {
public:
    RandomizedSet() {}
    vector<int>v;
    unordered_map<int,int>mp;
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
          return false;
        v.push_back(val);
      mp[val]=v.size()-1;  
      return true;
    }
    
    bool remove(int val) {
      if(mp.find(val)==mp.end())
         return false;
      v[mp[val]]=v[v.size()-1];
      mp[v[v.size()-1]]=mp[val];
      
      v.pop_back();
      mp.erase(val);
      
      return true;
    }
  
   int getRandom(){
     return v[rand()%v.size()];
   }
};
