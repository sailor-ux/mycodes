#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        string str;
        unordered_map<char, int> mp; //��ϣ���޷�����ֵvalue������
        vector<pair<char, int>> vec; //��ϣ��ת���vec���棬vecͨ��sort���Զ���ĺ�����������
        for (const char& ch : s) {
            mp[ch]++;
        }
        for (auto& it : mp) {
            vec.push_back(it); // itֱ��push_back��ȥ����
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