class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Step 1: Sort the array first
        // Because we need to pick elements in order: max, min, 2nd max, 2nd min, ...
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Step 2: Initialize two pointers
        int max_i = n - 1;   // index of current maximum element
        int min_i = 0;       // index of current minimum element

        // Step 3: Choose a number greater than the maximum element in the array
        // This will help us encode two values (old + new) in a single index
        int me = arr[n - 1] + 1;

        // Step 4: Traverse array and encode new values into existing indices
        for (int i = 0; i < n; i++) {
            
            // Even index → place next maximum element
            if (i % 2 == 0) {
                arr[i] += (arr[max_i] % me) * me;
                max_i--;
            } 
            // Odd index → place next minimum element
            else {
                arr[i] += (arr[min_i] % me) * me;
                min_i++;
            }
        }

        // Step 5: Decode the array
        // Each element currently has two numbers encoded:
        // new value = arr[i] / me
        // old value  = arr[i] % me
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / me;
        }
    }
};
