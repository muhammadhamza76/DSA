# Rearrange Array Alternately

This program rearranges a sorted array so that elements appear in an alternating order of maximum and minimum values.

Example:  
Input: [1, 2, 3, 4, 5, 6]  
Output: [6, 1, 5, 2, 4, 3]

---

### Approach
1. First, sort the array.
2. Use two pointers:
   - One starting from the beginning (min element)
   - One from the end (max element)
3. Use a number greater than the maximum element to encode both values in one place.
4. After rearranging, decode the final values by dividing each element by that number.

This method avoids using extra space.

---

### Complexity
- **Time:** O(n log n) because of sorting  
- **Space:** O(1) (in-place)

---

### Code
```cpp
class Solution {
  public:
    void rearrange(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max_i = n - 1, min_i = 0;
        int me = arr[n - 1] + 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] += (arr[max_i] % me) * me;
                max_i--;
            } else {
                arr[i] += (arr[min_i] % me) * me;
                min_i++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / me;
        }
    }
};
