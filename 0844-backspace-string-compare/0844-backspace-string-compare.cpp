class Solution {
public:
    bool backspaceCompare(string s, string t) {
       int i = s.size(); int j = t.size();
    int skip_S = 0, skip_T = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') {
                skip_S++;
                i--;
            } else if (skip_S > 0) {
                skip_S--;
                i--;
            } else {
                break;
            }
        }

        while (j >= 0) {
            if (t[j] == '#') {
                skip_T++;
                j--;
            } else if (skip_T > 0) {
                skip_T--;
                j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    return true;

    }
};