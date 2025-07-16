class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int count = 0;
        int limit = sqrt(n) + 1;
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        // Sieve of Eratosthenes
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Case 1: p^8 <= n
        for (int p : primes) {
            long long p8 = 1;
            for (int i = 0; i < 8; i++) {
                p8 *= p;
                if (p8 > n) break;
            }
            if (p8 <= n) count++;
        }

        // Case 2: p^2 * q^2 <= n (p != q)
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n) count++;
                else break; // Since primes are increasing, no further j will satisfy
            }
        }

        return count;
    }
};

