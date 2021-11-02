//Time:  O(N);
//Space: O(1);
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i<j){
            while(i<j && !(isalpha(s[i]) || isdigit(s[i]))) i++;
            while(i<j && !(isalpha(s[j]) || isdigit(s[j]))) j--;
            if(i<j && (tolower(s[i++]) != tolower(s[j--])))
                return false;
        }
        return true;
    }
};
