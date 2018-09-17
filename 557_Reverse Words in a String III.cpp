class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        bool fstch = false;
        int left = 0;
        while(index < s.size())
        {
            if( fstch && s[index] == ' ')
            {
                fstch = false;
                int l = left , r= index -1;
                while(l<r) swap(s[l++] , s[r--]);
            }
            else if(!fstch && s[index] != ' ')
            {
                left = index;
                fstch = true;
            }
            index++;
            if(index >= s.size())
            {
                int l = left ,r = index -1;
                while(l<r) swap(s[l++],s[r--]);
            }
        }
        return s;
    }
};
