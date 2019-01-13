/* 42 Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * example:
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
 
//某一格能储存的雨水量取决于左右两侧较低的挡板
//分别求某一格左右两侧延伸的最高挡板高度
//储存的雨水量就是左右两侧最低的高度减去当前格原本的高度之和
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        int maxh = INT_MIN;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > maxh) {
                left[i] = height[i];
                maxh = height[i];
            }
            else left[i] = maxh;
        }
        maxh = INT_MIN;
        for(int i = height.size() - 1; i >= 0; i--){
            if(height[i] > maxh) {
                right[i] = height[i];
                maxh = height[i];
            }
            else right[i] = maxh;
        }
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            int h = min(left[i], right[i]);
            sum += (h - height[i]);
        }
        return sum;
    }
};