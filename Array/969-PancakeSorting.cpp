/**969 Pancake Sorting
 * Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
 * Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 * Note:
 * 1 <= A.length <= 100
 * A[i] is a permutation of [1, 2, ..., A.length]
 */
 
class Solution {
public:
    vector<int> ans;
    
    void flip(int k, vector<int>& A) {
        for (int i = 0; i < k - i - 1; i++)
            swap(A[i], A[k - i - 1]);
        ans.push_back(k);
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        for (int i = n; i >= 1; i--) {
            // put i on place i
            int index = 0;
            while (A[index] != i && index < n) index++;
            if (index == i - 1) continue;
            flip(index + 1, A);
            flip(i, A);
        }
        return ans;
    }
};