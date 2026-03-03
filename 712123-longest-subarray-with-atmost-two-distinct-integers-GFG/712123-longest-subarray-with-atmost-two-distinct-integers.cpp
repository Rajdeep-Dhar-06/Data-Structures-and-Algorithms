class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int j = 0, d = 0, n = arr.size(), ans = 0;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            if(mp[arr[i]]==0) d++;
            mp[arr[i]]++;
            
            while(j<=i && d>2){
                mp[arr[j]]--;
                if(mp[arr[j]]==0) {
                    mp.erase(arr[j]);
                    d--;
                }
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};