static string M[] = {"", "M", "MM", "MMM"};//千
static string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//百
static string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//十
static string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//个

class Solution {
public:
    string intToRoman(int num) {
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
