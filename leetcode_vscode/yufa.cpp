#include <iostream>
using namespace std;

int main() {
    // char* p = "abc"; // �еı��벻ͨ�������Ǻ���ȷ
    const char* p = "abc"; // ����ָ�룬p����ջ�ռ䣬������ָ����sizeof����8�ֽ�(64λ�Ĳ���ϵͳ)
    char a[5] = "abcd";    // һά�������������ָ�볣������ָ�롢��������Ԫ�صĵ�ַ��һ��ָ��
    char b[] = "abcd";
    // a++;      //����
    // b++;      //����
    // *p = 'x'; //����
    cout << *(p++); // a, *(p++)<=>*p++, �������*p, Ȼ��p++
    // *p = 'x'; //����
    cout << *p; // b
    cout << p[1] << ' ' << a[2] << ' ' << b[2] << endl;
    cout << *p << sizeof(p) << endl;
    cout << *a << sizeof(a) << endl; // sizeof(������)=����Ĵ�С
    cout << *b << sizeof(b) << endl; // sizeof(������)=����Ĵ�С
    char s[] = "abcd";
    cout << *(*(&s + 1) - 2) << endl; // d
    cout << s << endl;                // abcd
    system("pause");
    return 0;
    // ��ά������������Ǹ�����ָ��
    // ����ָ�����ָ���������顢����һά����
}