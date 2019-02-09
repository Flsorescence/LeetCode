/* 88 Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 *   The number of elements initialized in nums1 and nums2 are m and n respectively.
 *   You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * example：
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * Output: [1,2,2,3,5,6]
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m + n > nums1.size() + nums2.size()) return;
        int temp[m+n], i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j])
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }
        while(i < m) temp[k++] = nums1[i++];
        while(j < n) temp[k++] = nums2[j++];
        copy(temp, temp+m+n, nums1.begin());
    }
};