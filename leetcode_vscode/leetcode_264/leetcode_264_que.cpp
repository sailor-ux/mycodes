#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> vec{2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> q; //���ȶ���q����װ�صĶ��ǳ���
        unordered_set<long> st;                              //�Ѿ�������еĳ���
        q.push(1);
        st.insert(1);
        while (1) {
            long num = q.top();
            q.pop();
            if (--n == 0) {
                return num;
            }
            for (const long& x : vec) {
                if (!st.count(x * num)) {
                    q.push(x * num);
                    st.insert(x * num);
                }
            }
        }
    }
};
int main() {
    Solution sol;
    cout << sol.nthUglyNumber(10);
    system("pause");
    return 0;
}