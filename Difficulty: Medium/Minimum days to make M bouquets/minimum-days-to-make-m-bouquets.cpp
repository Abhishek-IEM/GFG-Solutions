class Solution {
public:
    bool canMake(vector<int>& arr, int day, int k, int m) {
        int count = 0, bouquets = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; // reset after forming a bouquet
                }
            } else {
                count = 0; // break in sequence
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long total = 1LL * k * m;
        if ((long long)arr.size() < total) return -1; // not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, mid, k, m)) {
                ans = mid;
                high = mid - 1; // try smaller
            } else {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};
