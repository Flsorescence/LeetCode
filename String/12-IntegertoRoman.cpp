/**12 Integer to Roman
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 */


class Solution {
public:
    string intToRoman(int num) {
        string m[4]={"","M","MM","MMM"};
        string c[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string x[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string i[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return m[num/1000]+c[num%1000/100]+x[num%100/10]+i[num%10];
    }
};