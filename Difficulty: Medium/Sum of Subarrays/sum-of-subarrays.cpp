class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            int contribution = arr[i] * (i + 1) * (n - i);
            totalSum += contribution;
        }
        
        return totalSum;
    }
};