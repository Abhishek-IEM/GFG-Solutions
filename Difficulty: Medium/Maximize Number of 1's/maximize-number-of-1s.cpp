class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, zeros = 0, maxLen = 0;
    
        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] == 0) {
                zeros++;
            }
    
            // Shrink window until zeros <= k
            while (zeros > k) {
                if (arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
    
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
    
        return maxLen;
    }

};
