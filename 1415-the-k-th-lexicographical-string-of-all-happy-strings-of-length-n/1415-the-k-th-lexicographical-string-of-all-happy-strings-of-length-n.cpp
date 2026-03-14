class Solution {
public:
    int cnt;
    string ans;
    void backtrack(string s, char prev, int i, int n, int k) {
        if (i == n) {
            cnt++;
            if (cnt >= k) {
                if (cnt == k) {
                    ans = s;
                }
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (ch != prev && cnt < k) {
                backtrack(s + ch, ch, i + 1, n, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        cnt = 0;
        ans = "";
        backtrack("", 'A', 0, n, k);
        return ans;
    }
};