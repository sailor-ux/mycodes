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
                cout << "��һ��û�����ݣ�" << endl;
                continue;
            }
            int maxVal = INT_MIN;
            while (m--) {
                cin >> num;
                maxVal = max(maxVal, num);
            }
            cout << "���ֵ = " << maxVal << endl;
        }
    }
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    system("pause");
    return 0;
}