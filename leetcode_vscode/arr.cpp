#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[4][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int arr1[3]{0, 1, 2};
    cout << sizeof(arr) << endl;
    cout << sizeof(*arr) << endl; // *arr <=> 一维数组{1, 2, 3}的数组名
    cout << **arr << endl;
    cout << typeid(arr).name() << endl;
    // *arr = arr1; // 错误
    int n = 10;
    // int arr2[n]; // 错误
    int* candies1 = new int[n]{100, 100, 100, 100, 1000, 100, 100, 100, 100, 100};
    // int* candies2 = new int[n]{100} // 数组长度为n, 第0个元素为100，其余默认为0！！
    cout << candies1[0] << ' ' << *(candies1 + 9) << ' ' << candies1[4] << endl;
    vector<int> candies2(n, 1);
    system("pause");
    return 0;
}