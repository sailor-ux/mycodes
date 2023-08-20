#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp; // key-б��k, int-��б�ʳ��ֵĴ���
            int cnt = 0;
            for (int j = i + 1; j < n; j++) { // ������ö�ٵ���iʱ������ֻ��Ҫ���Ǳ�Ŵ���i�ĵ㵽��i��б�ʣ���Ϊ���ֱ��ͬʱ�������С�ڵ�i�ĵ�j����ô������ö�ٵ�jʱ���Ѿ����ǹ���ֱ���ˣ���
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                string k = calcK(x1, y1, x2, y2);
                mp[k]++;
                cnt = max(cnt, mp[k]);
            }
            ans = max(ans, cnt + 1);
        }
        return ans;
    }
    string calcK(int x1, int y1, int x2, int y2) {
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        int maxComDiv = gcd(dx, dy); // gcd�����������Լ��
        string k = to_string(dy / maxComDiv) + '_' + to_string(dx / maxComDiv);
        if ((x1 - x2) * (y1 - y2) < 0) {
            return '-' + k;
        }
        return k;
    }
};
int main() {

    system("pause");
    return 0;
}
