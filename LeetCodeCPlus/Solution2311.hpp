//
//  Solution2311.hpp
//  LeetCodeCPlus
//
//  Created by Peng on 2023/11/9.
//

#ifndef Solution2311_hpp
#define Solution2311_hpp

#include <stdio.h>

#include <math.h>

using namespace std;
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <set>
#include <queue>
#include <numeric>

class Solution2311 {
public:
    
    /// #1
    /// 给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，它表示一个网格图。每个格子为下面 3 个值之一：
    ///
    /// - 0 表示草地。
    /// - 1 表示着火的格子。
    /// - 2 表示一座墙，你跟火都不能通过这个格子。
    
    /// 一开始你在最左上角的格子 (0, 0) ，你想要到达最右下角的安全屋格子 (m - 1, n - 1) 。每一分钟，你可以移动到 相邻 的草地格子。每次你移动 之后 ，着火的格子会扩散到所有不是墙的 相邻 格子。
    ///
    /// 请你返回你在初始位置可以停留的 最多 分钟数，且停留完这段时间后你还能安全到达安全屋。如果无法实现，请你返回 -1 。如果不管你在初始位置停留多久，你 总是 能到达安全屋，请你返回 10^9 。
    ///
    /// - 注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。
    ///
    /// 如果两个格子有共同边，那么它们为 相邻 格子。
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,1}, {0,-1}, {-1,-1}};
        
        /// 着火点
        queue<vector<int>> q;
        for (int i = 0; i < m; i++)  {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        
        auto isclamp = [](int v, int lo, int hi) {
            if (v >= lo && v <= hi) return true;
            return false;
        };
        
        /// 所有格子着火时间
        while (!q.empty()) {
            vector<int> coor = q.front();
            q.pop();
            int t = grid[coor[0]][coor[1]];
            t >>= 2; t += 1; t <<= 2;
            
            for (auto& dir : dirs) {
                int x = coor[0] + dir[0], y = coor[1] + dir[1];
                if (isclamp(x, 0, m-1) && isclamp(y, 0, n-1) &&
                    grid[x][y] == 0) {
                    grid[x][y] = t;
                    q.push({x, y});
                }
            }
        }
        
        if (grid[m-1][n-1] >> 2 == 0) {
            return 10e9;
        }
        
        /// 格子最短到达时间
        vector<vector<int>> steptime(m, vector<int>(n,-1));
        steptime[0][0] = 0;
        int t = 0;
        q.push({0,0});
        while (!q.empty()) {
            vector<int> coor = q.front();
            q.pop();
            t += 1;
            
            for (auto& dir : dirs) {
                int x1 = coor[0] + dir[0], y1 = coor[1] + dir[1];
                if (isclamp(x1, 0, m-1) && isclamp(y1, 0, n-1) &&
                    grid[x1][y1] == 0 && steptime[x1][y1] == -1) {
                    if (grid[x1][y1] >> 2 < t)
                        continue;
                    
                    steptime[x1][y1] = t;
                    q.push({x1, y1});
                }
            }
        }
        
        if (grid[m-1][n-1] >> 2 < steptime[m-1][n-1]) {
            return -1;
        }
        int ans = (grid[m-1][n-1] >> 2) - steptime[m-1][n-1];
        int last = min(steptime[m-1][n] > 0 ? : 1e9, steptime[m][n-1] > 0 ? : 1e9);
        if (last == steptime[m-1][n]) {
            if ((grid[m-1][n] >> 2) - steptime[m-1][n] == ans + 1) {
                ans--;
            }
        }
        else {
            if ((grid[m][n-1] >> 2) - steptime[m][n-1] == ans + 1) {
                ans--;
            }
        }
        return ans;
    }
    
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8)
            return false;
        
        bool hasdigit = false, haslower = false, hasupper = false;
//        for (int i = 0; i < password.size(); i++) {
//            if (!hasdigit)
//                isdigit(password[i]);
//            if (!haslower)
//                islower(password[i]);
//            if (!hasupper)
//                isupper(password[i]);
//        }
        
        return true;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int res = 0;
        for (int i = 0; i < n; i+=2) {
            int a = row[i];
            int b = a^1;
            if (row[i+1] == b) {
                continue;
            }
            for (int j = i+2; j < n; j ++) {
                if (row[j] == b) {
                    swap(row[j], row[i+1]);
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
};

#endif /* Solution2311_hpp */
