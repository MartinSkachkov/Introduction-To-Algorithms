#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> cost_r(n + 1);
  vector<int> cost_g(n + 1);
  vector<int> cost_b(n + 1);
  int pr, pg, pb;
  for (size_t i = 1; i <= n; i++) {
    cin >> pr >> pg >> pb;
    cost_r[i] = pr;
    cost_g[i] = pg;
    cost_b[i] = pb;
  }

  vector<vector<int>> dp(3, vector<int>(n + 1));
  vector<int> opt_r(n + 1, 0);
  vector<int> opt_g(n + 1, 0);
  vector<int> opt_b(n + 1, 0);

  opt_r[1] = cost_r[1];
  opt_g[1] = cost_g[1];
  opt_b[1] = cost_b[1];

  for (size_t i = 2; i <= n; i++) {
    opt_r[i] = cost_r[i] + min(opt_g[i - 1], opt_b[i - 1]);
    opt_g[i] = cost_g[i] + min(opt_r[i - 1], opt_b[i - 1]);
    opt_b[i] = cost_b[i] + min(opt_g[i - 1], opt_r[i - 1]);
  }

  int minCost = min(opt_r[n], opt_g[n]);
  minCost = min(minCost, opt_b[n]);

  cout << minCost << endl;

  return 0;
}