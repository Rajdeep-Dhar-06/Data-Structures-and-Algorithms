class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int sum = 0, ops = 0;
        int n = arr.size();
        vector<int> diff(n, 0);
        for(int i=0; i<n; i++){
            sum += diff[i];
            int x = (sum + arr[i] + 2)%2;
            if(x==0){
                if(i+k>n) return -1;
                sum += 1;
                if(i+k<n) diff[i+k] -= 1;
                ops++;
            }
        }
        return ops;
    }
};