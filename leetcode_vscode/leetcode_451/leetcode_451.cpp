#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        string str;
        unordered_map<char, int> mp; //哈希表无法根据值value来排序
        vector<pair<char, int>> vec; //哈希表转存进vec里面，vec通过sort和自定义的函数进行排序
        for (const char& ch : s) {
            mp[ch]++;
        }
        for (auto& it : mp) {
            vec.push_back(it); // it直接push_back进去就行
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        for (auto& [ch, num] : vec) {
            for (int i = 0; i < num; i++) {
                str.push_back(ch);
            }
        }
        return str;
    }
};
int main() {

    system("pause");
    return 0;
}