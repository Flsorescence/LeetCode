/**135 Candy
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 * Example 1:
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 */
 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 0) return 0;
        if(len == 1) return 1;
        vector<int> candy1(len, 1);
        vector<int> candy2(len, 1);
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1]) candy1[i] = candy1[i-1] + 1;
        }
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) candy2[i] = candy2[i+1] + 1;
        }
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += max(candy1[i], candy2[i]);
        } 
        return sum;
    }
};