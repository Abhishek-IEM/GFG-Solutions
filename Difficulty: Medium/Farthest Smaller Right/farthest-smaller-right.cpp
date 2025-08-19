class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffixMin(n);
        vector<int> ans(n, -1);

        suffixMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(arr[i], suffixMin[i+1]);
        }

        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1, best = -1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (suffixMin[mid] < arr[i]) {
                    best = mid;   // valid, but try to go farther right
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            ans[i] = best;
        }
        return ans;
    }
};
