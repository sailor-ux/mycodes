#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[4][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int arr1[3]{0, 1, 2};
    cout << sizeof(arr) << endl;
    cout << sizeof(*arr) << endl; // *arr <=> һά����{1, 2, 3}��������
    cout << **arr << endl;
    cout << typeid(arr).name() << endl;
    // *arr = arr1; // ����
    int n = 10;
    // int arr2[n]; // ����
    int* candies1 = new int[n]{100, 100, 100, 100, 1000, 100, 100, 100, 100, 100};
    // int* candies2 = new int[n]{100} // ���鳤��Ϊn, ��0��Ԫ��Ϊ100������Ĭ��Ϊ0����
    cout << candies1[0] << ' ' << *(candies1 + 9) << ' ' << candies1[4] << endl;
    vector<int> candies2(n, 1);
    system("pause");
    return 0;
}