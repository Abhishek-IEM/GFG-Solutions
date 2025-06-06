class Solution {
  public:
    vector<int> computeLPS(string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m;) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> search(string &pat, string &txt) {
    int n = txt.size();
    int m = pat.size();
    vector<int> ans;
    
    vector<int> lps = computeLPS(pat);
    
    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            ans.push_back(i - j + 1); // 1-based indexing
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return ans;
    }
};