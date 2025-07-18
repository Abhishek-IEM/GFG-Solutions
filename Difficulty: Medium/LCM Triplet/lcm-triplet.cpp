class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    long long lcm(long long a, long long b, long long c) {
        return lcm(a, lcm(b, c));
    }

    long long lcmTriplets(int n) {
        if (n <= 2) return n; // For n=1,2
        if (n == 3) return 6; // lcm(1,2,3)=6

        long long ans = 0;
        if (n % 2 != 0) {
            ans = lcm(n, n - 1, n - 2);
        } else {
            // For even n, check both options:
            // 1) n, n-1, n-3
            // 2) n-1, n-2, n-3
            ans = max(lcm(n, n - 1, n - 3), lcm(n - 1, n - 2, n - 3));
        }
        return ans;
    }
};
