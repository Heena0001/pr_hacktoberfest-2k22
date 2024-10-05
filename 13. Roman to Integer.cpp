#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        // Map to hold the values of Roman numerals
        std::unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int prevValue = 0; // Keep track of the previous numeral value

        // Traverse the Roman numeral string from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            char currentChar = s[i];
            int currentValue = romanMap[currentChar];

            // If the current value is less than the previous value, it should be subtracted
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue; // Otherwise, add the value
            }

            prevValue = currentValue; // Update previous value
        }

        return total;
    }
};

// Example usage
int main() {
    Solution solution;
    std::cout << "III: " << solution.romanToInt("III") << std::endl;          // Output: 3
    std::cout << "IV: " << solution.romanToInt("IV") << std::endl;            // Output: 4
    std::cout << "IX: " << solution.romanToInt("IX") << std::endl;            // Output: 9
    std::cout << "LVIII: " << solution.romanToInt("LVIII") << std::endl;      // Output: 58
    std::cout << "MCMXCIV: " << solution.romanToInt("MCMXCIV") << std::endl;  // Output: 1994
    return 0;
}
