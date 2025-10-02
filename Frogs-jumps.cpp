// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int> leaves_ar;
        for(int i=1;i<=leaves;i++){
            leaves_ar.push_back(i);
        }
        for(int i=0;i<N;i++)
        {
          
          for(int j=0;j<leaves_ar.size();j++)
        {
          if(leaves_ar[j]==-1){
              continue;
          }
          else if(leaves_ar[j]%frogs[i]==0){
              leaves_ar[j]=-1;
          }
          
          
                  }
                  }
                  int count=0;
                  for(int i=0;i<leaves_ar.size();i++)
        {
          if(leaves_ar[i]!=-1)
          count++;
                  }
                  
            if(count)
            return count;
            else  
            return 0;
       
    }
   
};
