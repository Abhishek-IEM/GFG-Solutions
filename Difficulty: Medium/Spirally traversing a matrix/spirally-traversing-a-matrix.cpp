//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int minr = 0, minc = 0, maxr = n - 1, maxc = m - 1;
        int total = n*m, count = 0;
        
        while(minr <= maxr && minc <= maxc && count <= total)
        {
            if(minr > maxr || minc > maxc || count > total) return ans;
            for(int j = minc; j <= maxc; j++)
            {
                ans.push_back(matrix[minr][j]);
                count++;
            }
            minr++;
            if(minr > maxr || minc > maxc || count > total) return ans;
            for(int i = minr; i <= maxr; i++)
            {
                ans.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            if(minr > maxr || minc > maxc || count > total) return ans;
            for(int j = maxc; j >= minc; j--)
            {
                ans.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;
            if(minr > maxr || minc > maxc || count > total) return ans;
            for(int i = maxr; i >= minr; i--)
            {
                ans.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return  ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends