class Solution {
public:
    int mySqrt(int x)  {
        int val = x;
        int counter = 0; 
        int index = 1;
       while (val > 0 )
       {   
           counter++;
           index += 2;
           val -= index;                      
       }        
        return counter;        
    }
};
