/**84 Largest Rectangle in Histogram
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * example:
 * Input: [2,1,5,6,2,3]
 * Output: 10
 */
 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack<int> tmp;
        tmp.push(heights[0]);
        int res = heights[0];
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] >= tmp.top()) tmp.push(heights[i]);
            else{
                int len = 1;
                while(!tmp.empty() && tmp.top() > heights[i]) {
                    int t = tmp.top();
                    tmp.pop();
                    res = max(t * len, res);
                    len++;
                }
                
                tmp.push(heights[i]);
                for(int j = 0; j < len - 1; j++)
                    tmp.push(heights[i]);
                
            }
        }
        int count = 1;
        while(!tmp.empty()){
            res = max(res, tmp.top() * count);
            tmp.pop();
            count ++;
        }
        return res;
    }
};