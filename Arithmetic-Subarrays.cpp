class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        vector<bool> ans_arr(r.size());
        for (int i = 0; i < l.size(); i++) {
            vector<int> temp_arr;
            for (int j = l[i]; j <= r[i]; j++) {
                temp_arr.push_back(nums[j]);
            }
            sort(temp_arr.begin(), temp_arr.end());
            bool is_seq = 1;
            int diff = temp_arr[1] - temp_arr[0];
            for (int k = 0; k < temp_arr.size() - 1; k++) {
                if (temp_arr[k + 1] - temp_arr[k] != diff) {
                    is_seq = 0;
                    break;
                }
            }
            if (is_seq)
                ans_arr[i] = 1;
            else
                ans_arr[i] = 0;
        }
        return ans_arr;
    }
};