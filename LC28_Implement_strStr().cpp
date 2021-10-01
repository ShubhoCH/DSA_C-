class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int index = haystack.find(needle);
        return index;
    }
};
