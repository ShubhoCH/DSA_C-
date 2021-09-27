class Solution {
public:
    //NAIVE:
    int maxArea(vector<int>& height) {
        vector< pair <int, int> > v;
        //index:height
        int ans = 0;
        v.push_back(make_pair(0,height[0]));
        for(int i=1;i<height.size();i++){
            if(height[i]>v[v.size()-1].second)
                v.push_back(make_pair(i,height[i]));
            for(int j=0, temp = 0;j<v.size();j++){
                temp = min(height[i], v[j].second) * (i - v[j].first);
                ans = (temp>ans)?temp:ans;
            }
        }
        return ans;
    }
    //OPTIMAL: O(N)
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i=0,j=height.size()-1;i<j;){
            int temp = (j-i)*min(height[i],height[j]);
            if( temp > ans )
                ans = temp;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
