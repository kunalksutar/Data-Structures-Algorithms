#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, q; cin >> n >> q;
    vector<vector<char>> grid(n, 
    vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> prefix(n+1,
    vector<long long> (n+1, 0));

    // 1. cumilating elements from left to right 
    for (int i = 0; i < n; i++) {
        long long totalTrees = 0;

        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                totalTrees++;
            }

            prefix[i+1][j+1] = totalTrees;
        }
    }

    // 2. cumilating elements from top to bottom
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            prefix[i][j] += prefix[i-1][j];
        }
    }

    for (int i = 0; i < q; i++) {
        long long y1, x1, y2, x2; 
        cin >> y1 >> x1 >> y2 >> x2;

        long long trees = prefix[y2][x2]-prefix[y2][x1-1]-prefix[y1-1][x2]+prefix[y1-1][x1-1];

        cout << trees << endl;
    }

    return 0;
}
