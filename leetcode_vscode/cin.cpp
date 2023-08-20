#include <iostream>
using namespace std;

int main() {
    int n, m, num;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        while (n--) {
            cin >> m;
            if (m == 0) {
                cout << "这一行没有数据！" << endl;
                continue;
            }
            int maxVal = INT_MIN;
            while (m--) {
                cin >> num;
                maxVal = max(maxVal, num);
            }
            cout << "最大值 = " << maxVal << endl;
        }
    }
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    system("pause");
    return 0;
}