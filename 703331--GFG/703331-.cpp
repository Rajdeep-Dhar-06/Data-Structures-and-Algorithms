class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
      int n=arr1.size(), m=arr2.size();
      int s=0, e=m-1;
      int dif=INT_MAX;
      vector<int> ans(2);
      
      while(s<n && e>=0){
        int csum=arr1[s]+arr2[e];
        int cdif=abs(csum-x);
        
        if(dif>cdif){
          dif=cdif;
          ans[0]=arr1[s];
          ans[1]=arr2[e];          
        }
        
        
        if(csum==x) return {arr1[s], arr2[e]};
        
        if(csum<x) s++;
        else e--;
        
      }
      
      return ans;
    }
};