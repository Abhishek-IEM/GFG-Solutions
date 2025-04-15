//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();

        auto nextGap = [](int gap) {
            if (gap <= 1) return 0;
            return (gap / 2) + (gap % 2);
        };
    
        int gap = nextGap(n + m);
    
        while (gap > 0) {
            int i = 0, j = gap;
    
            while (j < n + m) {
                int val_i = (i < n) ? a[i] : b[i - n];
                int val_j = (j < n) ? a[j] : b[j - n];
    
                if (val_i > val_j) {
                    if (i < n && j < n)
                        swap(a[i], a[j]);
                    else if (i < n && j >= n)
                        swap(a[i], b[j - n]);
                    else
                        swap(b[i - n], b[j - n]);
                }
    
                i++;
                j++;
            }
    
            gap = nextGap(gap);
        }
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends