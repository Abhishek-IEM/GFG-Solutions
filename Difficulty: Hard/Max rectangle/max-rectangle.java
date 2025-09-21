class Solution {
    
    public static int MAH(int arr[]){
        int n=arr.length;
        Stack<Integer>st=new Stack<>();
        
        int NSR[]=new int [n];
        for(int i=0;i<n;i++){
            NSR[i]=n;
        }
        
        int NSL[]=new int [n];
        for(int i=0;i<n;i++){
            NSL[i]=-1;
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                NSR[i]=st.peek();
            }
            st.push(i);
        }
        st.clear();
        
          for(int i=0;i<n;i++){
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                NSL[i]=st.peek();
            }
            st.push(i);
        }
        int width[]=new int[n];
        
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int max=-1;
        for(int i=0;i<n;i++){
            max=Math.max(max,arr[i]*width[i]);
        }
        return max;
        
    }
    static int maxArea(int mat[][]) {
        // code here
        int n=mat[0].length;
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=mat[0][i];
        }
        int max=MAH(arr);
        
        for(int i=1;i<mat.length;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    arr[j]=0;
                }else{
                    arr[j]=mat[i][j]+arr[j];
                }
            }
            max=Math.max(max,MAH(arr));
        }
        return max;
    }
}