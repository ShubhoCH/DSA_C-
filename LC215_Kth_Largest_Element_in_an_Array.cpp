//Time:  O(N)=>Time Complexty of Building a Heap with N elements is O(N);
//Time:  O(N);
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: nums){
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
