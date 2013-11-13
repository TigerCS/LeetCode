/*
http://oj.leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

// Time: O(m*n) Space: O(n)
int uniquePaths(int m, int n) {
    vector<int> sum(n, 0);
    for(int i=0; i<m; i++) {
        sum[0] = 1;
        for(int j=1; j<n; j++) {
            sum[j] += j>0 ? sum[j-1] : 1;
        }
    }
    return sum[n-1];
}
