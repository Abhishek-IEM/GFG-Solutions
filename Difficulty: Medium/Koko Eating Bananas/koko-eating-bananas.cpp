class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
    
        auto canEatAll = [&](int s) -> bool {
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + s - 1) / s; // ceil(pile / s)
            }
            return hours <= k;
        };
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(mid)) {
                ans = mid;
                high = mid - 1; // try smaller s
            } else {
                low = mid + 1;  // s is too small, increase it
            }
        }
    
        return ans;
    }
};