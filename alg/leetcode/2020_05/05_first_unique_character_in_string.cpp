#include <map>

class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char, int> repetitions;
        for (int i = 0; i < s.length(); i++) {
            std::map<char,int>::iterator it = repetitions.find(s[i]);
            if (it == repetitions.end()) {
                repetitions.insert(std::pair<char, int>(s[i], 1));
            } else {
                it->second = it->second + 1;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (repetitions.find(s[i])->second == 1) {
                return i;
            }
        }
        return -1;
    }
};