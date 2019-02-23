/**6 ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 */
 
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 0 || numRows <= 1) return s;
        int step = 1, row = 0;
        int len = s.length();
        string* tmp = new string[numRows];
        for(int i = 0; i < len; i++){
            tmp[row] += s[i];
            if(row == 0)
                step = 1;
            if(row == numRows - 1)
                step = -1;
            row += step;
        }
        s.clear();
        for(int i = 0; i < numRows; i++) {
            s += tmp[i];
        }
        return s;
    }
};