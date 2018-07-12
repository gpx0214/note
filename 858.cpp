/*
https://leetcode.com/problems/mirror-reflection/description/

There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)

Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.

21
.0

---X2X2X2X2X
--X0X0X0X0X0
-12121212121
.0X0X0X0X0X0
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int gcd(int x1, int x2) {
		int a1 = x1;
        int a2 = x2;
        while (a1 != a2) {
            cout << a1 << " " << a2 << endl;
			if (a1 < a2) a2-=a1;
			else a1 -= a2;
		}
        return a1;
	};
    int mirrorReflection(int p, int q) {
		int a = gcd(p, q);
        cout << p/a << " " << q/a << endl;
        if (p/a%2) {
			if (q/a%2) {
                // 1 1
				return 1;
			} else {
				// 1 0
				return 0;
			}
		} else {
			if (q/a%2) {
				// 0 1
				return 2;
			} else {
				// 0 0
				return mirrorReflection(p/a/2, q/a/2);
			}
		}
        return a;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int p = stringToInteger(line);
        getline(cin, line);
        int q = stringToInteger(line);
        
        int ret = Solution().mirrorReflection(p, q);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
