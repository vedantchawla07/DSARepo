class Solution {
public:
    bool isPalindrome(string s) {

        int low = 0, high = s.size() - 1;
        while (low < high) {
            if (!((s[low] >= '0' && s[low] <= '9') || (s[low] >= 'a' && s[low] <= 'z') || (s[low] >= 'A' && s[low] <= 'Z'))) {
                low++;
                continue;
            }
            if (!((s[high] >= '0' && s[high] <= '9') || (s[high] >= 'a' && s[high] <= 'z') || (s[high] >= 'A' && s[high] <= 'Z'))) {
                high--;
                continue;
            }
            if (tolower(s[low]) != tolower(s[high])) return false;
            low++;
            high--;
        }
        return true;
    }
};