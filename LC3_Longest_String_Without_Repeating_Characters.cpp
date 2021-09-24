class Solution {
public:
    //NAIVE SOLUTION:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), count = 0;
        for(int i=0;i<n && count<=n-i-1;i++){
            unordered_map<char, int> map;
            int temp = 0;
            for(int j=i; j<n && (temp + n-j-1 >= count); j++){
                if( map.find(s[j]) == map.end() ){   
                    temp++;
                    map[s[j]] = j;
                }
                else{
                    i=map[s[j]];
                    break;
                }
            }
            if(temp > count)
                count=temp;
        }
        return count;
    };
    //OPTIMIZED SOLUTION:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l=0,r=0;
        unordered_map<char, int> map;
        int count = 0;
        for(int i=0;i<n;i++,r++){
            if(map.find(s[r]) == map.end()){
                map[s[r]] = i;
            }
            else{
                if(map[s[r]] >= l){
                    l=map[s[r]] + 1;
                    map[s[r]] = i;
                }
                else
                    map[s[r]] = i;
            }
            if(count<r-l+1)
                count = r-l+1;
        }
        return count;
    };
};
