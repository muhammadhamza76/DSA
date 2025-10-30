class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        //this is for  the max  non wrapping case 
        long long max_sum=arr[0],current_max=arr[0];
        for (int i=1;i<arr.size();i++){
            current_max=max((long long)arr[i],arr[i]+current_max);
            max_sum=max(max_sum,current_max);
        }
        
        // this the min sum for the non wrapping
         long long min_sum=arr[0],current_min=arr[0];
        for (int i=1;i<arr.size();i++){
            current_min=min((long long)arr[i],arr[i]+current_min);
            min_sum=min(min_sum,current_min);
        }
        
        
        // now find the max sum of the wrapping 
        // but it will require me the trick;
        
        // max_wap_sum=total_sum_arr-min_sub_arr_sum;
        
        // now find total_sum_arr
        long long total_sum_arr=0;
        for (int i=0;i<arr.size();i++){
           total_sum_arr+=(long long)arr[i];
        }
        if (max_sum < 0) return max_sum;
        
        long long max_wrapping_sum=total_sum_arr-min_sum;
        
        return max(max_wrapping_sum,max_sum);
        
    }
};