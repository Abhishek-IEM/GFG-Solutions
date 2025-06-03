class Solution {
  public:
     int countAtMostK(string& s, int k) {
        // code here.
        int n = s.size();
        int freq[26] = {0};
        int count = 0, i = 0, distinct = 0;

        for (int j = 0; j < n; j++) {
            if (freq[s[j] - 'a'] == 0) {
                distinct++;
            }
            freq[s[j] - 'a']++;

            while (distinct > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) {
                    distinct--;
                }
                i++;
            }

            count += (j - i + 1);
        }

        return count;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        if (k == 0) return 0;  // Edge case
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};