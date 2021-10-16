class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      digits[n-1]+=1;
      for(int i=n-1;i>0;i--)
      {
          if(digits[i]>9)
          {
              digits[i] %=10;
              digits[i-1]+=1;
          }
      }
        if(digits[0]>9)
        {
            digits[0] %=10;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
