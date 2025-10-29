class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size(),count=0,cand;
        for(int i=0;i<n;i++)    {
                if(count==0){
                    count++;
                    cand=arr[i];
                }
                else{
                    if(cand==arr[i])
                    count++;
                    else count--;
                }
        }
        count=0;
        for(int i=0;i<n;i++)    {
                if(cand==arr[i])
                count++;
                
        }
        if(count>n/2)
        return cand;
else return -1;       
       
        return 0;
    }
};