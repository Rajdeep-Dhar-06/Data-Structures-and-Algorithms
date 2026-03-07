class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string x = "";
        for(int i=0; i<2*n; i++){
            x += i%2 ? '1' : '0';
        }
        int curr = 0, ans = 1e9;
        for(int i=0; i<2*n; i++){
            if(s[i] != x[i]) curr++;
            if(i>=n){
                if(s[i-n] != x[i-n]) curr--;
            }
            if(i>=n-1)
                ans = min({ans, curr, n-curr});
        }
        return ans;
    }
};