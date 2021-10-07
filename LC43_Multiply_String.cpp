//Something is wrong:
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int v[400] = { 0 };
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int product = (num1[i] - 48) * (num2[j] - 48);
                int index = num1.length() - 1 - i + num2.length() - 1 - j;
                if (v[index] + product % 10 < 10 && v[index + 1] + product / 10 < 10) {
                    v[index] += product % 10;
                    v[index + 1] += product / 10;
                }
                else {
                    int i = index;
                    v[index] += product % 10;
                    while (v[i] > 9) {
                        int temp = v[i];
                        v[i] = v[i] % 10;
                        v[i + 1] += temp / 10;
                        i++;
                    }
                    i = index + 1;
                    while (v[i] > 9) {
                        int temp = v[i];
                        v[i] = v[i] % 10;
                        v[i + 1] += temp / 10;
                        i++;
                    }
                }
            }
            if (i == 0)
                v[num1.length() + num2.length()] = -1;
        }
        string ans = "";
        for (int i = num1.length() + num2.length() - 1; v[i] == 0; i--)
            v[i] = -1;
        for (int i = 0; v[i] != -1; i++)
            ans = to_string(v[i]) + ans;
        return ans;
    }
};
