#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (int end = 1; end <= n; end++) {
            for (int i = 0; i < n - end; i++) {
                cout << ' ';
            }
            for (int num = 1; num <= end; num++) {
                cout << num;
            }
            for (int num = end - 1; num >= 1; num--) {
                cout << num;
            }
            cout << "\n";
        }
        for (int end = n - 1; end >= 1; end--) {
            for (int i = 0; i < n - end; i++) {
                cout << ' ';
            }
            for (int num = 1; num <= end; num++) {
                cout << num;
            }
            for (int num = end - 1; num >= 1; num--) {
                cout << num;
            }
            cout << "\n";
        }
    }
    return 0;
}