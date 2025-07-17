class Solution {
public:
    int maxKPower(int n, int k) {
        map<int, int> primeFactors;
        int temp = k;
        for (int i = 2; i * i <= temp; i++) {
            while (temp % i == 0) {
                primeFactors[i]++;
                temp /= i;
            }
        }
        if (temp > 1) primeFactors[temp]++;

        int ans = INT_MAX;

        for (auto it : primeFactors) {
            int p = it.first;
            int a = it.second;

            int cnt = 0;
            long long power = p;
            while (power <= n) {
                cnt += n / power;
                power *= p;
            }

            ans = min(ans, cnt / a);
        }

        return ans;
    }
};
