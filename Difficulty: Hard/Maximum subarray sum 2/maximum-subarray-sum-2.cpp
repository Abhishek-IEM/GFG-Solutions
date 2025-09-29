class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + arr[i];

        long long ans = LLONG_MIN;
        multiset<long long> window; 

        for (int r = 0; r < n; r++) {
            // add prefix for subarray ending at r with length >= a
            if (r - a + 1 >= 0) {
                window.insert(pref[r - a + 1]);
            }
            // remove prefix that exceeds length > b
            if (r - b >= 0) {
                window.erase(window.find(pref[r - b]));
            }
            if (!window.empty()) {
                ans = max(ans, pref[r+1] - *window.begin());
            }
        }
        return (int)ans;
    }
};
