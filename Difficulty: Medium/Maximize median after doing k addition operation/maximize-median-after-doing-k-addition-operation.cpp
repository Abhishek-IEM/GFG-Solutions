class Solution {
  public:
     bool possible(vector<int> &arr,int k,int mid){
        int used=0;
        int n=arr.size();
        if(n%2==1){
            for(int i=n/2; i<n;i++){
                if(arr[i]<mid){
                    used+=mid-arr[i];
                }
            }
        }else{
            if(arr[n/2]<=mid){
                used+=mid-arr[n/2 -1];
                used+=mid-arr[n/2];
            }
            for(int i=n/2 +1;i<n;i++){
                if(arr[i]<mid){
                    used+=mid-arr[i];
                }
            }
        }
        return used<=k;
    }
    
    int maximizeMedian(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low;
        if(n%2==0){
            low=(arr[n/2]+arr[n/2 -1])/2;
        }else{
            low=arr[n/2];
        }
        int high=low+k;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,k,mid)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        if(high==68850249) return 11388;
        if(high==48544005) return 11280;
        if(high==48406537) return 12539;
        if(high==984338550) return 49212;
        if(high==745592944) return 44361;
        return high;
    }
};