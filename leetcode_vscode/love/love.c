#include "stdio.h"
#include "stdlib.h"
int main() {
    float i = 1.5;
    int sum = 0, index = 0;
    int flag = 1;
    for (float y = 1.5; y > -1.5; y -= 0.1) {
        for (float x = -1.5; x < 1.5; x += 0.05) {
            float a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0.0) {
                if (flag) {
                    printf("********×Þ¼ÒÁÖ ½ù­[½Ü********");
                    flag = 0;
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
    printf("·¬ÇÑ£¬");
    system("pause");
    return 0;
}