class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 1 && matrix[0].size() == 1) {
            if (matrix[0][0] == target) {
                return true;
            } else {
                return false;
            }
        }
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        int midRow, midCol;
        if (matrix.size() > 1) {
            while (u < d) {
                midRow = (u + d) / 2;
                if (matrix[midRow][0] > target) {
                    d = midRow - 1;
                } else if (matrix[midRow][r] < target) {
                    u = midRow + 1;
                } else if (matrix[midRow][0] <= target &&
                           matrix[midRow][r] >= target) {
                    break;
                }
            }
            if (matrix[u][r] >= target) {
                midRow = u;
            }
        }else {
            midRow=0;
        }
        if (matrix[midRow].size() == 1 && matrix[midRow][0] == target) {
            return true;
        }
        while (r > l) {
            midCol = (r + l) / 2;
            if (target == matrix[midRow][midCol]) {
                return true;
            } else if (target > matrix[midRow][midCol]) {
                l = midCol + 1;
            } else {
                r = midCol - 1;
            }
        }
        if(matrix[midRow][l]==target){
            return true;
        }

        return false;
    }
};