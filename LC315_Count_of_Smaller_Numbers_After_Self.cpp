//Time:  O(N*logN);
//Space: O(N);
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
	int n = nums.size();
	vector<int> result(n);
	vector<int> indices(n);
	iota(indices.begin(), indices.end(), 0);
	for (int size=1; size < n; size *= 2)
	{
		for (int l=0, m=l+size, r=min(m+size,n); m<n; l=r, m=l+size, r=min(m+size,n))
		{
			vector<int> temp;
			int i=l, j=m;
			while (i<m)
			{
				while (j<r && nums[indices[i]] > nums[indices[j]])
					temp.push_back(indices[j++]);
				result[indices[i]] += j-m;
				temp.push_back(indices[i++]);
			}
			copy(temp.begin(), temp.end(), indices.begin()+l);
		}
	}
	return result;
}
};
