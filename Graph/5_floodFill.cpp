/*733. Flood Fill

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the 
image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from
 the pixel image[sr][sc].

To perform a flood fill:

- Begin with the starting pixel and change its color to color.
- Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either 
horizontally or vertically) and shares the same color as the starting pixel.
- Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the 
original color of the starting pixel.
- The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same
 color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int num) {
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && image[i - 1][j] == num) {
                image[i - 1][j] = color;
                q.push({i - 1, j});
            }
            if (i + 1 < n && image[i + 1][j] == num) {
                image[i + 1][j] = color;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && image[i][j - 1] == num) {
                image[i][j - 1] = color;
                q.push({i, j - 1});
            }
            if (j + 1 < m && image[i][j + 1] == num) {
                image[i][j + 1] = color;
                q.push({i, j + 1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if (image[sr][sc] == color) return image;
        int num = image[sr][sc];
        bfs(image, sr, sc, color, num);
        return image;
    }
};

int main() {
    Solution sol;
    
    // Example input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1, sc = 1, newColor = 2; // Start at (1,1) and change color to 2
    
    cout << "Original Image:" << endl;
    for (auto row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
    
    cout << "\nFlood Filled Image:" << endl;
    for (auto row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
