/*
https://leetcode.com/problems/sum-of-two-integers/description/

371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (a&b)
            return getSum(a^b, (a&b)<<1);
        else 
            return a^b;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        
        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
