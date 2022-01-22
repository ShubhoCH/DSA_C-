//Time:  O(NlogM);
//Space: O(1);
class Solution {
public:
    bool check(vector<int>& bananas, int mid_val, int H)
    {
        int time = 0;
        for (int i = 0; i < bananas.size(); i++) {
            if (bananas[i] % mid_val != 0) {
                time += ((bananas[i] / mid_val) + 1);
            }
            else {
                time += (bananas[i] / mid_val);
            }
        }
        if (time <= H) {
            return true;
        }
        else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int H)
    {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while (start < end) {
            int mid = start + (end - start) / 2;
            if ((check(piles, mid, H)) == true) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return end;
    }
};
