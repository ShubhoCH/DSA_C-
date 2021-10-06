// O(N):
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, max_left = height[0], max_right= height[height.size() -1], left = 0, right= height.size() -1;
        while(left<=right){
            if(max_left < max_right){
                if(height[left] > max_left){
                    max_left = height[left];\
                    continue;
                }
                ans += max_left - height[left];
                left++;
            }
            else{
                if(height[right] > max_right){
                    max_right = height[right];
                    continue;
                }
                ans += max_right - height[right];
                right--;
            }
        }
        return ans;
    }
};

