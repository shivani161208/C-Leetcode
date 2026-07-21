class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string xc,yc,other;
        int n = s.size();
        xc.reserve(n);
        yc.reserve(n);
        other.reserve(n);

        for(char c :s){
            if(c == y) yc.push_back(c);
            else if(c == x) xc.push_back(c);
            else other.push_back(c);
        }
        return yc + other + xc;
    }
};