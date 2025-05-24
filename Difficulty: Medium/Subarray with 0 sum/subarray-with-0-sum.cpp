class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int> mp;
        
        int sum = 0;
        
        for(int num : arr)
        {
            sum += num;
            
            if(sum == 0 || mp.count(sum)) return true;
            
            mp.insert(sum);
        }
        
        return false;
    }
};