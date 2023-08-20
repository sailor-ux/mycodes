#include <iostream>
#include <vector>
using namespace std;
class Iterator {
    struct Data;
    Data* data;

public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    int curElement;
    bool flag;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        flag = Iterator::hasNext();
        if (flag) {
            curElement = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return curElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = curElement;
        flag = Iterator::hasNext();
        if (flag) {
            curElement = Iterator::next();
        }
        return ret;
    }

    bool hasNext() const {
        return flag;
    }
};
int main() {

    system("pause");
    return 0;
}