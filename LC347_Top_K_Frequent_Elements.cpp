//Time:  O(klogN); //K-> Top k frequent elements, N-> Total no of elements;
//Space: O(N);
class Solution {
    struct node{
        int no;
        int freq;
        node(int a, int b){
            no = a;
            freq = b;
        }
    };
    struct compare{
        bool operator()(node const& a, node const& b){
            return a.freq<b.freq;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        //Step-1: Store freq. of all elements in map;
        for(auto it: nums)
            m[it]++;
        //Step-2: Now build a heap;
        priority_queue<node, vector<node>, compare> heap;
        for(auto it:m)
            heap.push(node(it.first, it.second));
        vector<int> ans;    //Stores top-k elements;
        //Step-3: Pop top-k elements and store the numbers in ans vector
        while(k--){
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};
