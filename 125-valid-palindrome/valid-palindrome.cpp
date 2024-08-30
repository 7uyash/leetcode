
class Solution {
public:
    bool isPalindrome(const std::string &s, int left = 0, int right = -1) {
        if (right == -1) {
            right = s.size() - 1;
        }

       while (left < s.size() && !std::isalnum(s[left])) {
            ++left;
        }

          while (right >= 0 && !std::isalnum(s[right])) {
            --right;
        }

        if (left >= right) return true;

        if (std::tolower(static_cast<unsigned char>(s[left])) != std::tolower(static_cast<unsigned char>(s[right]))) {
            return false;
        }

        return isPalindrome(s, left + 1, right - 1);
    }
};