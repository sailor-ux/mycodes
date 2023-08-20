#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable1;
        vector<pair<int, int>> hashtable2;
        vector<int> res;
        for (const int& num : nums) {
            hashtable1[num]++;
        }
        for (const auto& keyValueDui : hashtable1) {
            hashtable2.push_back(keyValueDui);
        }
        sort(hashtable2.begin(), hashtable2.end(), comp);
        for (int i = 0; i < k; i++) {
            res.push_back(hashtable2[i].first);
        }
        return res;
    }
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) { // Ò»¶¨Òªstatic£¡£¡£¡
        return a.second > b.second;
    }
};
int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    Solution sol;
    vector<int> vec = sol.topKFrequent(nums, 2);
    for (const int& x : vec) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}