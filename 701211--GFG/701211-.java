class Solution {
    public int maxWater(int arr[]) {
        // code here
        int l=0;
        int r=arr.length-1;
        int water=0;
        int maxl=0;
        int maxr=0;
        while(l<r){
            if(arr[l]<arr[r]){
                if(arr[l]>maxl){
                    maxl=arr[l];
                }
                water+=maxl-arr[l++];
            }
            else{
                if(arr[r]>maxr){
                    maxr=arr[r];
                }
                water+=maxr-arr[r--];
            }
        }
        return water;
    }
}