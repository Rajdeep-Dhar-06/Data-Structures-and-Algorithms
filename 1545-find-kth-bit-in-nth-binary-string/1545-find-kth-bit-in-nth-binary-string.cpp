class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i < n; i++) {
            string x = s;
            string y = "";
            for (int j = x.size() - 1; j >= 0; j--) {
                y += x[j] == '1' ? "0" : "1";
            }
            s += "1" + y;
        }
        return s[k-1];
    }
};