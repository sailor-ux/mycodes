#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;
        for (int i = 1; i < n; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= R;
            R *= nums[i];
        }
        return answer;
    }
};
int main() {
    
    system("pause");
    return 0;
}