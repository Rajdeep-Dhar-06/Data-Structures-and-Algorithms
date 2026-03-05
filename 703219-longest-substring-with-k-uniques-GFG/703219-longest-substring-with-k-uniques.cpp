class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        map<char, int> mp;
        int n = s.size();
        int i = 0, j = 0, d = 0, ans = -1;
        for(; i<n; i++){
            if(mp.find(s[i])==mp.end()) d++;
            mp[s[i]]++;
            
            while(j<=i && d>k){
                mp[s[j]]--;
                if(mp[s[j]]==0) {
                    mp.erase(s[j]);
                    d--;
                }
                j++;
            }
            
            // cout << j << " " << i << endl;
            if(d==k) ans = max(ans, i-j+1);
        }
        return ans;
    }
};