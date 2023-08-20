#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string str;
        vector<string> res;
        int len = 0, begin = 0;
        for (int i = 0; i < words.size(); i++) {
            len += words[i].length();
            if (len + i - begin > maxWidth) { // 第i个单词不能选，选择begin~i-1个单词
                len -= words[i].length();
                i--;
                len += (i - begin);
                int spaceCount = maxWidth - len;
                if (i == begin) {
                    str += words[i];
                    str.append(spaceCount, ' ');
                } else {
                    int num = spaceCount / (i - begin);
                    int yushu = spaceCount % (i - begin);
                    for (int j = begin; j <= i; j++) {
                        str += words[j];
                        if (j < i) {
                            str.append(num + 1, ' ');
                        }
                        if (yushu > 0) {
                            str += ' ';
                            yushu--;
                        }
                    }
                }
                res.push_back(str);
                str = "";
                len = 0;
                begin = i + 1;
            } else if (i == words.size() - 1) {
                int spaceCount = maxWidth - len - (i - begin); // spaceCount>=0，最后一个word后面有spaceCount个空格
                for (int j = begin; j <= i; j++) {
                    str += words[j];
                    str += ' ';
                }
                if (spaceCount == 0) {
                    str.erase(str.end() - 1);
                } else {
                    str.append(spaceCount - 1, ' ');
                }
                res.push_back(str);
            }
        }
        return res;
    }
};
int main() {
    vector<string> words{"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"};
    Solution sol;
    words = sol.fullJustify(words, 16);
    for (const string& str : words) {
        cout << str << endl;
    }
    system("pause");
    return 0;
};
