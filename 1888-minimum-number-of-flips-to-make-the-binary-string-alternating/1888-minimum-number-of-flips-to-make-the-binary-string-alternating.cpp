class Solution {
public:
    int zeroMove(string s, int st) {
        string x = s;
        int ans = 0;
        for (auto ch : s) {
            if (ch - '0' != st)
                ans++;
            st = 1 - st;
        }
        return ans;
    }
    int oneMove(string s, int st) {
        string x = s.substr(1) + s[0];
        int ans = 0;
        for (auto ch : s) {
            if (ch - '0' != st)
                ans++;
            st = 1 - st;
        }
        return ans;
    }
    int twoMove(string s, int st) {
        string x = s.substr(2) + s[0] + s[1];
        int ans = 0;
        for (auto ch : s) {
            if (ch - '0' != st)
                ans++;
            st = 1 - st;
        }
        return ans;
    }
    int minFlips(string s) {
        return min({zeroMove(s, 0), zeroMove(s, 1), oneMove(s, 0),
                   oneMove(s, 1),  twoMove(s, 0),  twoMove(s, 1)});
    }
};