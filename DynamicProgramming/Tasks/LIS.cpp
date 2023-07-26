class Solution {
public:
  int findMax(const vector<int> &lis) {
    int max = INT_MIN;
    for (int l : lis) {
      if (l > max) {
        max = l;
      }
    }

    return max;
  }

  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> lis(n, 1);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          lis[i] = max(lis[i], 1 + lis[j]);
        }
      }
    }

    return findMax(lis);
  }
};