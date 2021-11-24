//LC
class Solution {
public:
    string originalDigits(string s) {
        string ret = "";
        unordered_map<int, int> A;
        for(char c:s)
        {
            if(c=='z') A[0]++;
            if(c=='w') A[2]++;
            if(c=='u') A[4]++;
            if(c=='x') A[6]++;
            if(c=='g') A[8]++;
            if(c=='s') A[7]++;
            if(c=='f') A[5]++;
            if(c=='h') A[3]++;
            if(c=='i') A[9]++;
            if(c=='o') A[1]++;
        }
        A[7]-=A[6];
        A[5]-=A[4];
        A[3]-=A[8];
        A[9]-=(A[5]+A[8]+A[6]);
        A[1]-=(A[0]+A[2]+A[4]);
        for(int i=0; i<10; i++)
        {
            while(A[i]>0)
            {
                ret+=to_string(i);
                A[i]--;
            }
        }
        return ret;
    }
};
