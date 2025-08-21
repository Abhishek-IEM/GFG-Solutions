class Solution {
    public int findKRotation(int arr[]) {
        // Code here
        int n = arr.length;
        int s = 0, e = n - 1;
        int minElement = Integer.MAX_VALUE;
        int minIndex = Integer.MAX_VALUE;
        
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            if(arr[s] <= arr[mid])
            {
                if(arr[s] < minElement)
                {
                    minElement = arr[s];
                    minIndex = s;
                }
                s = mid + 1;
            }
            else{
                if(arr[mid] < minElement)
                {
                    minElement = arr[mid];
                    minIndex = mid;
                }
                e = mid - 1;
            }
        }
        
        return minIndex;
    }
}