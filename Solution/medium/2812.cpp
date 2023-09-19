/*
2812. Find the Safest Path in a Grid (https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.


ex:
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).

Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    vector<pair<int,int>> movements = {{-1,0},{1,0},{0,-1},{0,1}}; 

    vector<vector<int>> BFS(vector<vector<int>>grid){
        int n = grid.size();
        vector<vector<int>> safenessTable(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int,int>> waiting;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    waiting.push({i,j});
                    safenessTable[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        while(!waiting.empty()){
            auto q = waiting.front();
            waiting.pop();
            int row = q.first;
            int col = q.second;
            int depth = safenessTable[row][col];

            for(auto mv : movements){
                int new_row = row - mv.first;
                int new_col = col - mv.second;
                if(0<=new_row && new_row<n && 0<=new_col && new_col<n && visited[new_row][new_col]!=true){
                    waiting.push({new_row,new_col});
                    safenessTable[new_row][new_col] = depth + 1;
                    visited[new_row][new_col] = true;
                }
            }
        }
        return safenessTable;
    }

    vector<vector<pair<int,int>>> Dijkstra(vector<vector<int>> safenessTable){
        int n = safenessTable.size();
        vector<vector<pair<int,int>>> parents(n, vector<pair<int,int>>(n, {-1,-1}));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push(make_pair(safenessTable[0][0], make_pair(0,0)));
        visited[0][0] = true;
        while(!pq.empty()){
            auto q = pq.top();
            pq.pop();
            int row = q.second.first;
            int col = q.second.second;

            for(auto mv : movements){
                int new_row = row - mv.first;
                int new_col = col - mv.second;

                if(0<=new_row && new_row<n && 0<=new_col && new_col<n && visited[new_row][new_col]!=true){
                    pq.push(make_pair(safenessTable[new_row][new_col], make_pair(new_row,new_col)));
                    visited[new_row][new_col] = true; 
                    parents[new_row][new_col] = {row, col};
                }
            }
        }
        return parents;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return 0;
        }

        vector<vector<int>> safenessTable = BFS(grid);
        vector<vector<pair<int,int>>> parents = Dijkstra(safenessTable);

        int safeFactor = INT_MAX;
        auto node = make_pair(n-1, n-1);
        while(node.first!=-1 || node.second!=-1){
            int _safeFactor = safenessTable[node.first][node.second];
            if(safeFactor>_safeFactor)
                safeFactor = _safeFactor;
            node = parents[node.first][node.second];
        }

        return safeFactor;
    }



    int maximumSafenessFactor_v1(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return 0;
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        vector<vector<int>> safeness(n, vector<int>(n,0));

        queue<pair<pair<int,int>, int>> queue;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    queue.push(make_pair(make_pair(i,j), 0));
                    visited[j][i] = true;
                }
            }
        }
        
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        while(queue.size()>0){
            pair<pair<int,int>, int> q = queue.front();
            queue.pop();
            safeness[q.first.second][q.first.first] = q.second;
            for(int i=0; i<4; i++){
                int new_x = q.first.first + dx[i];
                int new_y = q.first.second + dy[i];

                if(0<=new_x && new_x<n && 0<=new_y && new_y<n && visited[new_y][new_x] == false){
                    queue.push(make_pair(make_pair(new_x,new_y), q.second+1));
                    visited[new_y][new_x] = true;
                    safeness[new_y][new_x] = q.second;
                }
            }
        }

        vector<vector<bool>> visited2(n, vector<bool>(n,false));
        vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(n, make_pair(-1,-1)));

        priority_queue<pair<int, pair<int,int>>> queue2;
        queue2.push(make_pair(safeness[0][0], make_pair(0,0)));
        visited2[0][0] = true;
        int minSafety = INT_MAX;
        while(queue2.size()>0){
            pair<int, pair<int,int>> q = queue2.top();
            queue2.pop();

            visited2[q.second.second][q.second.first] = true;
            for(int i=0; i<4; i++){
                int new_x = q.second.first + dx[i];
                int new_y = q.second.second + dy[i];
                if(0<=new_x && new_x<n && 0<=new_y && new_y<n && visited2[new_y][new_x] == false){
                    queue2.push(make_pair(safeness[new_y][new_x], make_pair(new_x,new_y)));
                    visited2[new_y][new_x] = true;
                    parent[new_y][new_x] = make_pair(q.second.first, q.second.second);
                }
            }
        }

        pair<int,int> node = make_pair(n-1,n-1);
        while(node.first!=-1 && node.second!=-1){
            if(minSafety > safeness[node.second][node.first]){
                minSafety = safeness[node.second][node.first];
            }
            node = parent[node.second][node.first];
        }
        return minSafety;
    }
};