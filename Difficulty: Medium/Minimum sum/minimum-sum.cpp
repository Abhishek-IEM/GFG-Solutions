// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        string n1, n2;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            if(i % 2 == 0) n1 += to_string(arr[i]);
            else n2 += to_string(arr[i]);
        }
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        int i = 0, j = 0, carry = 0, n = n1.size(), m = n2.size();
        string ans;
        while(i < n || j < m)
        {
            int sum = 0;
            if(i < n) sum += n1[i++] - '0';
            if(j < m) sum += n2[j++] - '0';
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            ans += to_string(sum);
        }
        ans += to_string(carry);
        while(ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
