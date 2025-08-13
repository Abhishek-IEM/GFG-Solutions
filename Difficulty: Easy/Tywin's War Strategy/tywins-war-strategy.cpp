class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int requiredLucky = (n + 1) / 2; // ceil(n/2)
        
        int luckyCount = 0;
        vector<int> addNeeded;
    
        for (int x : arr) {
            if (x % k == 0) {
                luckyCount++;
            } else {
                addNeeded.push_back(k - (x % k));
            }
        }
    
        // If we already have enough lucky troops
        if (luckyCount >= requiredLucky) return 0;
    
        // Sort the additions needed for non-lucky troops
        sort(addNeeded.begin(), addNeeded.end());
    
        int soldiersToAdd = 0;
        int troopsNeeded = requiredLucky - luckyCount;
    
        for (int i = 0; i < troopsNeeded; i++) {
            soldiersToAdd += addNeeded[i];
        }
    
        return soldiersToAdd;
    }
};