/* 15 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:The solution set must not contain duplicate triplets.
 * example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */
 
//参考求解最大容量的思路，先对数组元素按升序排序，设置两个指针j, k, 从i=0开始对每个元素查找相加为0的另外两个数字的下标
//耗时较长
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        int j, k;
        for(int i = 0; i < nums.size(); i++){
            j = i + 1; k = nums.size() - 1;
            int tmp = -nums[i];
            while(j < k){
                if(tmp < nums[j] + nums[k]) k--;
                else if(tmp > nums[j] + nums[k]) j++;
                else{
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    int l = s.size();
                    s.insert(t);
                    if(s.size() > l) res.push_back(t);
                    k--; j++;
                }
            }
        }
        return res;
    }
};