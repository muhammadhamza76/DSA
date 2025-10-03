class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
    
        // Your code goes here
        
        
        sort(arr.begin(),arr.end());
        
        int sub=0,a=arr[0],diff=1,count=1;
        
        for (int i=1;i<arr.size();i++){
          
          if((arr[i]-a)==(diff)){
              diff++;
            //   count++;
            //   sub++;
          }
        //   if(sub && (arr[i]-a)!=(diff))
        //   {count-=(sub-1);
        //       sub=0;
        //   }
          
          
          
           else if((arr[i]-a)!=(diff)){
              diff=1;
              a=arr[i];
              count++;
            //   sub++;
          }
        }
        return count;
    
    }
};