class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size(), count = 0;
        sort(arr.begin(), arr.end());
        for(int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while(i < j)
            {
                if(arr[i] + arr[j] > arr[k])
                {
                    count += j - i;
                    j--;
                }
                 else i++;
            }
        }
        return count;
    }
};

