class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        
        unordered_set<char> st(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); i++) {
            if (st.find(islower(s[i]) ? toupper(s[i]) : tolower(s[i])) == st.end()) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                return left.size() >= right.size() ? left : right;
            }
        }
        
        return s;
    }
};
