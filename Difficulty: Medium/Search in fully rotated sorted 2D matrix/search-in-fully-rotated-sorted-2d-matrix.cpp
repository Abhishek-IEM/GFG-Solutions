class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m, col = mid % m;
            int midVal = mat[row][col];

            if (midVal == x) return true;

            // Find the "virtual" first and last values
            int lowVal = mat[low / m][low % m];
            int highVal = mat[high / m][high % m];

            // Left half is sorted
            if (lowVal <= midVal) {
                if (lowVal <= x && x < midVal) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (midVal < x && x <= highVal) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
