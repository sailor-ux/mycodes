#include <iostream>
using namespace std;
int main() {
    float i = 1.5;
    int sum = 0, index = 0;
    bool flag = true;
    for (float y = 1.5; y > -1.5; y -= 0.1) {
        for (float x = -1.5; x < 1.5; x += 0.05) {
            float a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0.0) {
                if (flag) {
                    cout << "********×Þ¼ÒÁÖ ½ù­[½Ü********";
                    flag = false;
                    break;
                }
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        system("color 0c");
        putchar('\n');
    }
    cout << "·¬ÇÑ£¬";
    system("pause");
    return 0;
}