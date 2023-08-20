#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    // unordered_set<int> set;
    // set.insert(0);
    // set.insert(1);
    // set.insert(0);
    // for (unordered_set<int>::iterator iter = set.begin(); iter != set.end(); iter++) {
    //     cout << *iter << ' ';
    // }
    // cout << "\n"
    //      << set.count(1) << ' ' << set.count(2);
    // cout << "\n---------------\n";
    // auto vec = vector<int>({34, 5});
    // vector<vector<int>> arr(3, vector<int>(2, 1));
    // for (const int& x : vec) {
    //     cout << x << ' ';
    // }
    // cout << "\n";
    // for (const vector<int>& vec : arr) {
    //     for (const int& x : vec) {
    //         cout << x << ' ';
    //     }
    //     cout << "\n";
    // }
    // cout << "\n---------------\n";
    // auto str = string("abcdef");
    // str.substr(1, 3); // str是不变的，substr返回string
    // cout << str;
    // // str = str.substr(1, 3);
    // str = str.substr(2);
    // cout << str;
    // cout << "\n---------------\n";
    // unordered_map<int, int> hash;
    // hash[9] = 0;
    // hash[0] = 1;
    // hash[7] = 2;
    // cout << hash.size();

    // vector在最前面插入
    // vector<int> vec{1, 2, 3, 4};
    // vec.insert(vec.begin(), 0);
    // for (auto x : vec) {
    //     cout << x << ' ';
    // }

    // int x = 100;
    // int y = 2;
    // string str = to_string(x) + "-" + to_string(y);
    // cout << str;

    // vector<int> vec{1, 2, 3, 4};
    // vec.erase(vec.begin() + 2);
    // for (auto x : vec) {
    //     cout << x << ' ';
    // }

    // string s = "abcdef";
    // cout << s.substr(3) << ' ' << s;
    // string s = "";
    // cout << s[0];

    // string str("123abc 123.4one two three four");
    // stringstream ss(str);
    // string s1, s2;
    // int x;
    // string y;
    // ss >> x >> s1 >> y >> s2;
    // cout << x << ' ' << s1 << ' ' << y << ' ' << s2.c_str() << endl;
    // while (ss >> s1) {
    //     cout << s1 << ' ';
    // }
    // cout << "\n"
    //      << typeid(y).name();

    /* string str = "123.321.45";
    int pos = -1;
    while ((pos = str.find(".", pos + 1)) != string::npos) { // 不存在的位置，!=才表示能找到、存在; 也可以看作是-1，虽然实际值不是-1
        cout << str.substr(pos + 1) << endl;
    }
    cout << string::npos;
    // cout << str.substr(3); */

    /* vector<int> vec{1, 2, 3, 4};
    vector<int> vec1;
    vec1.assign(vec.begin() + 1, vec.end()); */

    int n = 10;
    system("pause");
    return 0;
}