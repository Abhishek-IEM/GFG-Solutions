class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int maxSum = INT_MIN, minSum = INT_MAX, totalSum = 0;
        int s1 = 0, s2 = 0, n = arr.size();
    
        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
    
            s1 += arr[i];
            maxSum = max(maxSum, s1);
            if(s1 < 0) s1 = 0;
    
            s2 += arr[i];
            minSum = min(minSum, s2);
            if(s2 > 0) s2 = 0;
        }
    
        // Handle all-negative case
        if(maxSum < 0) return maxSum;
    
        return max(maxSum, totalSum - minSum);
    }
};
