// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0)
      return false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
      int midpos = left + (right - left) / 2;
      int midelem = matrix[midpos / cols][midpos % cols];
      if (midelem == target) {
        return true;
      } else if (midelem < target) {
        left = midpos + 1;
      } else {
        right = midpos - 1;
      }
    }
    return false;
  }
};