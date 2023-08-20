#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> hashMap;
        for (const string& cpdomain : cpdomains) {
            stringstream ss(cpdomain);
            int times, pos = -1;
            string domain;
            ss >> times >> domain;
            hashMap[domain] += times;
            while ((pos = domain.find('.', pos + 1)) != string::npos) {
                hashMap[domain.substr(pos + 1)] += times;
            }
        }
        for (unordered_map<string, int>::iterator it = hashMap.begin(); it != hashMap.end(); it++) {
            res.push_back(to_string(it->second) + ' ' + it->first);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}