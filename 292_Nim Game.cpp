// 1(1)  2(2)  3(4)  4 (7)  5(13)  6(24) 7(44) 8(81) 9(149)
class Solution {
public:
    bool canWinNim(int n) {
       return (n-1)%4 == 0 || (n-2)%4 == 0 || (n-3)%4 == 0 ;
    }
};
