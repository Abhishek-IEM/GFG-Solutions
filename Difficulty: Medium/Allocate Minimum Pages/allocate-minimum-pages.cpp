class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        int sta = 0;
        long long end, mid, ans;
        for(int i = 0; i < n; i++)
        {
            sta = max(sta, arr[i]);
            end += arr[i];
        }
        long long start = sta;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            long long pages = 0, count = 1;
            for(int i = 0; i < n; i++)
            {
                pages += arr[i];
                if(pages > mid)
                {
                    count++;
                    pages = arr[i];
                }
            }
            if(count <= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
             start = mid + 1;
        }
        return ans;
    }
};