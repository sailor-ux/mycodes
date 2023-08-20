#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch;
    int n;
    while (1) { // cin >> ch >> n
        cin >> ch;
        if (ch == '@') {
            break;
        }
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            cout << " ";
        }
        // cout << string(n - 1, ' ');
        cout << ch << endl;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2 - i; j++) {
                cout << " ";
            }
            // cout << string(n - 2 - i, ' ');
            cout << ch;
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << " ";
            }
            // cout << string(2 * i, ' ');
            cout << ch << endl;
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << ch;
        }
        cout << endl
             << endl;
    }
    return 0;
}