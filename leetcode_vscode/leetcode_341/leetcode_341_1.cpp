#include <iostream>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger>& getList() const;
};

class NestedIterator {
public:
    int idx;
    int n;
    NestedIterator* ptr;
    vector<NestedInteger>& nestedList;
    NestedIterator(vector<NestedInteger>& nestedList) : nestedList(nestedList) {
        idx = 0;
        n = nestedList.size();
        ptr = nullptr;
    }

    int next() {
        if (ptr == nullptr) { // nestedList[idx].isInteger()
            return nestedList[idx++].getInteger();
        }
        return ptr->next();
    }

    bool hasNext() {
        while (idx < n) {
            if (nestedList[idx].isInteger()) {
                return true;
            }
            if (ptr == nullptr) {
                ptr = new NestedIterator(nestedList[idx].getList());
            }
            if (ptr->hasNext()) {
                return true;
            }
            delete ptr;
            ptr = nullptr;
            idx++;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {

    system("pause");
    return 0;
}