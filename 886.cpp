/*
866. Prime Palindrome

Find the smallest prime palindrome greater than or equal to N.
Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 
For example, 2,3,5,7,11 and 13 are primes.
Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 
For example, 12321 is a palindrome.

Example 1:

Input: 6
Output: 7

Example 2:

Input: 8
Output: 11

Example 3:

Input: 13
Output: 101

9989999
100030001

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
    bool isPrime(int N) {
        if (N < 2)
            return false;
        int R = (int)sqrt(N);
        for (int d = 2; d <= R; ++d)
            if (N % d == 0)
                return false;
        return true;
    }

    bool IsPalindromeNum(int num) {
        char s[10], i = 0, j;
        while (num > 0) {
            s[i] = num % 10 + '0';
            num = num / 10;
            i++;
        }
        s[i] = '\0';
        i--;
        for (j = 0; j < (i + 1) / 2; j++) {
            if (s[j] != s[i - j])
            {
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int N) {
        while (true) {
            if (IsPalindromeNum(N) && isPrime(N)) {
                return N;
            }
            N++;
            if (10000000 < N && N < 100000000) {
                N = 100000000;
            }
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line))
    {
        int N = stringToInteger(line);

        int ret = Solution().primePalindrome(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
