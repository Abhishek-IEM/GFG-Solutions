class Solution {
  public:
    int computeSum(const vector<int>& arr, int divisor) 
    {
        int sum = 0;
        for (int num : arr) {
            sum += (num + divisor - 1) / divisor;  
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int answer = high;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = computeSum(arr, mid);
    
            if (sum <= k) {
                answer = mid;      
                high = mid - 1;
            } else {
                low = mid + 1;    
            }
        }
        return answer;
    }
};
