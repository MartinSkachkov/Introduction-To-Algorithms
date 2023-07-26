class Solution {
public:
  int findMax(const vector<int> &nums) {
    int max = INT_MIN;

    for (int num : nums) {
      if (num > max) {
        max = num;
      }
    }

    return max;
  }

  int maxProduct(vector<int> &nums) {
    pair<int, int> p = {1, 1}; // that's dp
    int res = findMax(nums);

    for (int num : nums) {
      if (num == 0) {
        p.first = 1;
        p.second = 1;
        continue;
      }

      int tmp = p.first * num;
      p.first = max({num * p.first, num * p.second, num});
      p.second = min({tmp, num * p.second, num});
      res = max({p.first, p.second, res});
    }

    return res;
  }
};