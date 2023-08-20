#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    unordered_map<string, vector<string>> children; // 有向图
    vector<string> path;
    vector<vector<string>> ans;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 参考127题的双向BFS进行有向图children的构建，构建beginWord->endWord的有向图
        // DFS回溯对有向图进行搜索，寻找beginWord->endWord的所有路径
        // 有向图中的路径恰为全部的最短路径！！！
        // 本来s2中的节点全部属于dict，但是s2中的节点又都在dict中被擦除了，所以s2中的节点全都不属于dict，所以错了！
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return ans;
        }
        bool found = false, beginToEnd = true;
        unordered_set<string> s1{beginWord}, s2{endWord};
        while (!s1.empty() && !s2.empty() && !found) {
            for (const string& word : s1) {
                dict.erase(word);
            }
            for (const string& word : s2) {
                dict.erase(word);
            }
            if (s1.size() > s2.size()) {
                swap(s1, s2);
                beginToEnd = !beginToEnd;
            }
            unordered_set<string> s;
            for (string word : s1) {
                string cur = word;
                for (int i = 0; i < word.length(); i++) {
                    char ch = word[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        string parent = cur, child = word;
                        if (!beginToEnd) {
                            swap(parent, child);
                        }
                        if (s2.count(word)) {
                            found = true; // 存在beginWord->endWord的路径
                            children[parent].push_back(child);
                        } else if (dict.count(word) && !found) { // 设置found更远的路径不考虑，只考虑最短路径，所以有向图中的路径都是最短路径，并且全部的最短路径都在有向图中了
                            s.insert(word);
                            children[parent].push_back(child);
                        }
                    }
                    word[i] = ch;
                }
            }
            s1 = s;
        }
        if (found) {
            path.push_back(beginWord);
            dfs(beginWord, endWord);
        }
        return ans;
    }
    void dfs(const string& curWord, const string& endWord) { // 搜索curWord->endWord的所有路径，注意curWord已在路径path中，并且在最后一个（更好写！！！）
        if (curWord == endWord) {
            ans.push_back(path);
            return;
        }
        for (const string& child : children[curWord]) {
            path.push_back(child);
            dfs(child, endWord);
            path.pop_back();
        }
    }
    /* void dfs(string curWord, string endWord) { // 搜索curWord->endWord的所有路径，注意curWord还不在路径path中
        path.push_back(curWord);
        if (curWord == endWord) {
            // path.push_back(curWord);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        // path.push_back(curWord);
        for (const string& child : children[curWord]) {
            dfs(child, endWord);
        }
        path.pop_back();
    } */
};
int main() {
    vector<string> wordList{"aaaaa", "waaaa", "wbaaa", "xaaaa", "xbaaa", "bbaaa", "bbwaa", "bbwba", "bbxaa", "bbxba", "bbbba", "wbbba", "wbbbb", "xbbba", "xbbbb", "cbbbb", "cwbbb", "cwcbb", "cxbbb", "cxcbb", "cccbb", "cccwb", "cccwc", "cccxb", "cccxc", "ccccc", "wcccc", "wdccc", "xcccc", "xdccc", "ddccc", "ddwcc", "ddwdc", "ddxcc", "ddxdc", "ddddc", "wdddc", "wdddd", "xdddc", "xdddd", "edddd", "ewddd", "ewedd", "exddd", "exedd", "eeedd", "eeewd", "eeewe", "eeexd", "eeexe", "eeeee", "weeee", "wfeee", "xeeee", "xfeee", "ffeee", "ffwee", "ffwfe", "ffxee", "ffxfe", "ffffe", "wfffe", "wffff", "xfffe", "xffff", "gffff", "gwfff", "gwgff", "gxfff", "gxgff", "gggff", "gggwf", "gggwg", "gggxf", "gggxg", "ggggg", "wgggg", "whggg", "xgggg", "xhggg", "hhggg", "hhwgg", "hhwhg", "hhxgg", "hhxhg", "hhhhg", "whhhg", "whhhh", "xhhhg", "xhhhh", "ihhhh", "iwhhh", "iwihh", "ixhhh", "ixihh", "iiihh", "iiiwh", "iiiwi", "iiixh", "iiixi", "iiiii", "wiiii", "wjiii", "xiiii", "xjiii", "jjiii", "jjwii", "jjwji", "jjxii", "jjxji", "jjjji", "wjjji", "wjjjj", "xjjji", "xjjjj", "kjjjj", "kwjjj", "kwkjj", "kxjjj", "kxkjj", "kkkjj", "kkkwj", "kkkwk", "kkkxj", "kkkxk", "kkkkk", "wkkkk", "wlkkk", "xkkkk", "xlkkk", "llkkk", "llwkk", "llwlk", "llxkk", "llxlk", "llllk", "wlllk", "wllll", "xlllk", "xllll", "mllll", "mwlll", "mwmll", "mxlll", "mxmll", "mmmll", "mmmwl", "mmmwm", "mmmxl", "mmmxm", "mmmmm", "wmmmm", "wnmmm", "xmmmm", "xnmmm", "nnmmm", "nnwmm", "nnwnm", "nnxmm", "nnxnm", "nnnnm", "wnnnm", "wnnnn", "xnnnm", "xnnnn", "onnnn", "ownnn", "owonn", "oxnnn", "oxonn", "ooonn", "ooown", "ooowo", "oooxn", "oooxo", "ooooo", "woooo", "wpooo", "xoooo", "xpooo", "ppooo", "ppwoo", "ppwpo", "ppxoo", "ppxpo", "ppppo", "wpppo", "wpppp", "xpppo", "xpppp", "qpppp", "qwppp", "qwqpp", "qxppp", "qxqpp", "qqqpp", "qqqwp", "qqqwq", "qqqxp", "qqqxq", "qqqqq", "wqqqq", "wrqqq", "xqqqq", "xrqqq", "rrqqq", "rrwqq", "rrwrq", "rrxqq", "rrxrq", "rrrrq", "wrrrq", "wrrrr", "xrrrq", "xrrrr", "srrrr", "swrrr", "swsrr", "sxrrr", "sxsrr", "sssrr", "ssswr", "sssws", "sssxr", "sssxs", "sssss", "wssss", "wtsss", "xssss", "xtsss", "ttsss", "ttwss", "ttwts", "ttxss", "ttxts", "tttts", "wttts", "wtttt", "xttts", "xtttt", "utttt", "uwttt", "uwutt", "uxttt", "uxutt", "uuutt", "uuuwt", "uuuwu", "uuuxt", "uuuxu", "uuuuu", "zzzzz", "zzzzy", "zzzyy", "zzyyy", "zzyyx", "zzyxx", "zzxxx", "zzxxw", "zzxww", "zzwww", "zzwwv", "zzwvv", "zzvvv", "zzvvu", "zzvuu", "zzuuu", "zzuut", "zzutt", "zzttt", "zztts", "zztss", "zzsss", "zzssr", "zzsrr", "zzrrr", "zzrrq", "zzrqq", "zzqqq", "zzqqp", "zzqpp", "zzppp", "zzppo", "zzpoo", "zzooo", "zzoon", "zzonn", "zznnn", "zznnm", "zznmm", "zzmmm", "zzmml", "zzmll", "zzlll", "zzllk", "zzlkk", "zzkkk", "zzkkj", "zzkjj", "zzjjj", "zzjji", "zzjii", "zziii", "zziih", "zzihh", "zzhhh", "zzhhg", "zzhgg", "zzggg", "zzggf", "zzgff", "zzfff", "zzffe", "zzfee", "zzeee", "zzeed", "zzedd", "zzddd", "zzddc", "zzdcc", "zzccc", "zzccz", "azccz", "aaccz", "aaacz", "aaaaz", "uuuzu", "uuzzu", "uzzzu", "zzzzu"};
    Solution sol;
    vector<vector<string>> ans = sol.findLadders("aaaaa", "uuuuu", wordList);
    for (auto vec : ans) {
        for (auto str : vec) {
            cout << str << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}