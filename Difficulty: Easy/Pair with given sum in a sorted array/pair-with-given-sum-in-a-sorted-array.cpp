//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int s = 0, e = arr.size() - 1, count = 0;
        
        while(s < e)
        {
            int sum = arr[e] + arr[s];
            if(sum < target) s++;
            else if(sum > target) e--;
            else
            {
                int c1 = 0, c2 = 0, ele1 = arr[s], ele2 = arr[e];
                while(s <= e && arr[s] == ele1)
                {
                    c1++;
                    s++;
                }
                while(s <= e && arr[e] == ele2)
                {
                    c2++;
                    e--;
                }
                if(ele1 == ele2) count += c1*(c1 - 1)/2;
                else count += c1 * c2;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends