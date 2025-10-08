
class Solution {
public:
  long long countTriplets(int n, long long sum, long long arr[]) {
      sort(arr, arr + n);
      long long count = 0;

      for (int i = 0; i < n - 2; i++) {
          int j = i + 1;
          int k = n - 1;

          while (j < k) {
              long long s = arr[i] + arr[j] + arr[k];

              if (s < sum) {
                  count += (k - j); // all elements between j and k form valid triplets
                  j++;
              } else {
                  k--;
              }
          }
      }

      return count;
  }
};

int main() {
  int n = 4;
  long long arr[] = {5, 1, 3, 4};
  long long sum = 8;

  Solution obj;
  cout << obj.countTriplets(n, sum, arr) << endl;
  return 0;
}
