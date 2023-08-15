#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

vector<Interval> findMaxNestedIntervals(vector<Interval>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (intervals[i].start <= intervals[j].start && intervals[i].end >= intervals[j].end) {
                if (dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    parent[j] = i;
                }
            }
        }
    }

    int maxLen = *max_element(dp.begin(), dp.end());
    int maxIdx = distance(dp.begin(), max_element(dp.begin(), dp.end()));

    vector<Interval> nestedIntervals;
    while (maxIdx != -1) {
        nestedIntervals.push_back(intervals[maxIdx]);
        maxIdx = parent[maxIdx];
    }

    reverse(nestedIntervals.begin(), nestedIntervals.end());
    return nestedIntervals;
}

int main() {
    vector<Interval> intervals = {{1, 5}, {2, 8}, {3, 6}, {5, 10}, {7, 9}, {9, 12}};

    vector<Interval> result = findMaxNestedIntervals(intervals);

    for (const Interval& interval : result) {
        cout << "(" << interval.start << ", " << interval.end << ") ";
    }

    return 0;
}
