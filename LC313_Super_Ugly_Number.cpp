//Time:  O(N);
//Space: O(N);
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int N = primes.size();
        if(!N)
            return 1;
        vector<int> ans = {1};
        vector<int> primeIndexes(N,1);
        vector<int> minIndex;
        int temp, k, c,i;
        while(ans.size() < n)
        {
            temp = INT_MAX;
            c = 0;
            for(i=0;i<N;i++)
            {
                k = primes[i]*ans[primeIndexes[i]-1];
                if(k <= temp)
                {
                    if(k == temp)
                        c++;
                    else
                    {
                        temp = k;
                        c = 1;   
                    }
                    minIndex.push_back(i);
                }
            }
            int size = minIndex.size();
            for(i=size-1;i>=size-c;i--)
            {
                primeIndexes[minIndex[i]]++;
            }
            ans.push_back(temp);
            minIndex.clear();
        }
        return ans.back();
    }
};
