//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalSum = 0;
        
        for (int num : arr) {
            totalSum += num;
        }
        
        if (totalSum % 3 != 0) {
            return {-1, -1};
        }
        
        int partSum = totalSum / 3;
        int currentSum = 0;
        int firstSplit = -1, secondSplit = -1;
        
        for (int i = 0; i < n; ++i) {
            currentSum += arr[i];
            
            if (currentSum == partSum && firstSplit == -1) {
                firstSplit = i;
            }
            else if (currentSum == 2 * partSum && firstSplit != -1) {
                secondSplit = i;
                break;
            }
        }
        
        if (firstSplit != -1 && secondSplit != -1) {
            return {firstSplit, secondSplit};
        } else {
            return {-1, -1};
        }
    }
};








//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends