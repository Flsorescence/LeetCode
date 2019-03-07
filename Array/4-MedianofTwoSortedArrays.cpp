/**4 Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 */
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m == 0){
            if(n == 0) return 0.0;
            if(n % 2 == 0) return (nums2[n/2-1]+nums2[n/2])*1.0/2;
            else return nums2[n/2];
        }else if(n == 0){
            if(m % 2 == 0) return (nums1[m/2-1]+nums1[m/2])*1.0/2;
            else return nums1[m/2];
        }
        vector<int> tmp;
        int j = 0, k = 0;
        for(int i = 0; i < (m + n); i++){
            if(k == n){
                tmp.push_back(nums1[j]);
                j++;
            }else if(j == m){
                tmp.push_back(nums2[k]);
                k++;
            }else if(nums1[j] < nums2[k]){
                tmp.push_back(nums1[j]);
                j++;
            }
            else{
                tmp.push_back(nums2[k]);
                k++;
            }
        }
        if((m + n)% 2 == 0){
            return (tmp[(m+n)/2-1] + tmp[(m+n)/2])*1.0/2;
        }
        else return tmp[(m+n)/2];
    }
};