//Time:  O(M+N);
//Space: O(1);
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, k = m+n-1;
        for(i=m-1, j = n-1;i>=0 && j>=0;k--){
            if(nums1[i]>=nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
        }
        if(i>=0)return;
        for(;j>=0;j--)
            nums1[k--] = nums2[j];
    }
};
