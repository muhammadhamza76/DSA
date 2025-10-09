class Solution {
public:
    void booleanMatrix(vector<vector<int>>& mat) {
        // code here
    // int rows = mat.size(),cols=mat[0].size();
    
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //             if(mat[i][j]==1)
    //             mat[i][j]=-1;
    // }
    // }
    
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //             if(mat[i][j]==-1)
    //           {
    //               int a=i,b=0;
    //           while(b<cols){
    //               if(mat[a][b]==-1)
    //                               mat[a][b]=-1;
    //              else{
    //                   mat[a][b]=1;
                 
    //              } 
    //               b++;
    //           }
    //               a=0,b=j;
    //           while(a<rows){
    //                 if(mat[a][b]==-1)
    //               mat[a][b]=-1;
    //               else{
    //                   mat[a][b]=1;
                  
    //               }
    //              a++; 
    //           }
    //           }
    // }
    // }
    //  for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //             if(mat[i][j]==-1)
    //             mat[i][j]=1;
    // }
    // }
    
    
    // better but o(m+n) solution
    
    //  int rows = mat.size(),cols=mat[0].size();
    
    // int row_m[rows]={0},col_m[cols]={0};
    
    // for(int i=0;i<rows;i++){
        
    // for(int j=0;j<cols;j++){
    //     if(mat[i][j]==1){
    //         row_m[i]=1; 
    //         col_m[j]=1;
    //     }
        
    // }
        
    // }
    //   for(int i=0;i<rows;i++){
        
    // for(int j=0;j<cols;j++){
    //     if( row_m[i]==1 ||  col_m[j]==1 ){
    //      mat[i][j]=1;
           
    //     }
        
    // }
        
    // }
    
    
    //optimal solution

/// optimal solution 


        //  STEP 0: Basic dimensions
        int rows = mat.size(), cols = mat[0].size();

        //  STEP 1: Flags to remember if first row or first column originally had any 1
        // (We’ll need to restore them later because we’ll use them as markers.)
        bool row_one = 0, col_one = 0;

        // STEP 2: Check if first row contains any 1
        for (int j = 0; j < cols; j++) {
            if (mat[0][j] == 1) {
                col_one = 1;   // first row has a 1
                break;
            }
        }

        // STEP 3: Check if first column contains any 1
        for (int i = 0; i < rows; i++) {
            if (mat[i][0] == 1) {
                row_one = 1;   // first column has a 1
                break;
            }
        }

        // STEP 4: Use the first row and column as markers
        // If any cell (i,j) is 1 → mark its entire row and column by setting
        // mat[i][0] = 1  and  mat[0][j] = 1
        // (This avoids using extra arrays)
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][j] == 1) {
                    mat[i][0] = 1;   // mark this row
                    mat[0][j] = 1;   // mark this column
                }
            }
        }

        // STEP 5: Update cells based on markers
        // If either that row or column was marked → set current cell to 1
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][0] == 1 || mat[0][j] == 1) {
                    mat[i][j] = 1;
                }
            }
        }

        //  STEP 6: Finally, handle the first row if it originally had any 1
        if (col_one) {
            for (int j = 0; j < cols; j++) {
                mat[0][j] = 1;
            }
        }

        //  STEP 7: Handle the first column if it originally had any 1
        if (row_one) {
            for (int i = 0; i < rows; i++) {
                mat[i][0] = 1;
            }
        }
    }
};
