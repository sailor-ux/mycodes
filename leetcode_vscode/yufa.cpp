#include <iostream>
using namespace std;

int main() {
    // char* p = "abc"; // 有的编译不通过，不是很正确
    const char* p = "abc"; // 常量指针，p属于栈空间，对任意指针求sizeof都是8字节(64位的操作系统)
    char a[5] = "abcd";    // 一维数组的数组名是指针常量、常指针、是数组首元素的地址、一级指针
    char b[] = "abcd";
    // a++;      //错误
    // b++;      //错误
    // *p = 'x'; //错误
    cout << *(p++); // a, *(p++)<=>*p++, 先输出了*p, 然后p++
    // *p = 'x'; //错误
    cout << *p; // b
    cout << p[1] << ' ' << a[2] << ' ' << b[2] << endl;
    cout << *p << sizeof(p) << endl;
    cout << *a << sizeof(a) << endl; // sizeof(数组名)=数组的大小
    cout << *b << sizeof(b) << endl; // sizeof(数组名)=数组的大小
    char s[] = "abcd";
    cout << *(*(&s + 1) - 2) << endl; // d
    cout << s << endl;                // abcd
    system("pause");
    return 0;
    // 二维数组的数组名是个二级指针
    // 二级指针可以指向整个数组、整个一维数组
}