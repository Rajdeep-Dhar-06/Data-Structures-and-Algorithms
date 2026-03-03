class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int x = 0, ans = 0;
        for(int j=0; j<arr.size(); j++){
            x^=arr[j];
            if(j >= k-1){
                ans = max(ans, x);
                x ^= arr[j-k+1];
            }
            
        }
        
        return ans;
    }
};