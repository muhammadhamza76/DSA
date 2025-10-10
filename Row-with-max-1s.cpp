// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        // brute force approach of m*n
        
        
        
        // int rows=arr.size(),cols=arr[0].size();
        // int one_count=0,max_count=0,r_name=-1;
        
        // for(int i=0;i<rows;i++){
        //     one_count=0;
        //     for(int j=0;j<cols;j++){
        //     if(arr[i][j]==1)  {  one_count++;}
        //     }
        //     if(one_count>max_count){
        //         max_count=one_count;
        //         r_name=i;
        //     }
        // }
        // return r_name;
        
        //optimal solution
        
   
        int n = arr.size();
        int m = arr[0].size();
        
        int max_row = -1;
        int j = m - 1;  // start from top-right corner
        

        for (int i = 0; i < n; i++) {
            // move left while current element is 1
            
            //&& arr[i][j] == 0  just simply go down bcz of non 
            // decresing order we havwe already checked the high 1s row
            //than this row
            //like [[0,1,1,1], [0,0,1,1] [1,1,1,1], [0,0,0,0]]
            
            // in row 1st the 3 1s but inn2nd go down it will zero 
            // so that the mean is that 1s are less
            
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                max_row = i; // update row index
            }
        }
        
        return max_row;
    }
};

        
        