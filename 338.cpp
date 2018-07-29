/*
338. Counting Bits
https://leetcode.com/problems/counting-bits/description/
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOf1(int n) {
        int ret = 0;
        while(n){
            n = n & (n - 1);
            ret++;
        }
        return ret;
    }
    vector<int> countBits(int num) {
        vector<int> ret(0);
        for (int i=0; i<=num; i++) {
            ret.push_back(numberOf1(i));
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
