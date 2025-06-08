class Solution {
  public:
        bool isValid(const string &num) 
        {
            return !(num.length() > 1 && num[0] == '0');
        }

    string stringAdd(const string &a, const string &b) {
        string result;
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
    
        while (i >= 0 || j >= 0 || carry) {
            int digitA = (i >= 0) ? a[i--] - '0' : 0;
            int digitB = (j >= 0) ? b[j--] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
    
        reverse(result.begin(), result.end());
        return result;
    }

    bool checkSumString(const string &s, int start, string num1, string num2) {
        if (!isValid(num1) || !isValid(num2)) return false;
    
        string sum = stringAdd(num1, num2);
        int len = sum.length();
    
        if (start + len > s.length()) return false;
        if (s.substr(start, len) != sum) return false;
        if (start + len == s.length()) return true;
    
        return checkSumString(s, start + len, num2, sum);
    }

    bool isSumString(string &s) {
        int n = s.length();
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j - i);
    
                if (checkSumString(s, j, num1, num2))
                    return true;
            }
        }
        return false;
    }
};