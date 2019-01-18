/* 74 Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * example:
 * Input: 
 * [
 *   [1,3,5,7],
 *   [10,11,16,20],
 *   [23,30,34,50]
 * ]
 * target = 3
 * Output: true
 */

//使用两次二分法查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[0][0] > target || matrix[m-1][n-1] < target) return false;
        int low = 0, high = m-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        int low1 = 0, high1 = n - 1, tmp;
        while(low1 <= high1){
            int mid = (low1 + high1) / 2;
            if(matrix[low-1][mid] == target) return true;
            else if(matrix[low-1][mid] < target) low1 = mid + 1;
            else high1 = mid - 1;
            tmp = mid;
        }
        if(matrix[low-1][tmp] == target) return true;
        return false;
    }
};