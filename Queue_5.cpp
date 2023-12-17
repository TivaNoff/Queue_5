#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        int n = target.length(), m = stamp.length();
        int totalStamps = 0;

        auto canStamp = [&](int index) {
            bool stamped = false;
            for (int i = 0; i < m; ++i) {
                if (target[index + i] == '?') continue;
                if (target[index + i] != stamp[i]) return false;
                stamped = true;
            }
            return stamped;
            };

        auto doStamp = [&](int index) {
            for (int i = 0; i < m; ++i) {
                if (target[index + i] != '?') {
                    target[index + i] = '?';
                    totalStamps++;
                }
            }
            };

        while (totalStamps < 10 * n) {
            bool found = false;
            for (int i = 0; i <= n - m; ++i) {
                if (canStamp(i)) {
                    doStamp(i);
                    result.push_back(i);
                    found = true;
                }
            }

            if (!found) {
                break;
            }
        }

        reverse(result.begin(), result.end());

        return (totalStamps == n) ? result : vector<int>();
    }
};

int main() {
    Solution solution;

    string stamp1 = "abc";
    string target1 = "ababc";
    vector<int> result1 = solution.movesToStamp(stamp1, target1);

    cout << "Example 1: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    string stamp2 = "abca";
    string target2 = "aabcaca";
    vector<int> result2 = solution.movesToStamp(stamp2, target2);

    cout << "Example 2: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i < result2.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
