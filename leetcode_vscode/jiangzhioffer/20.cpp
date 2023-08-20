#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_SIGN,
        STATE_INT,
        STATE_POINT_LEFT_YES,
        STATE_POINT_LEFT_NO,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END_BLANK
        // STATE_END
    };
    enum CharType {
        CHAR_NUMBER,
        CHAR_POINT,
        CHAR_EXP,
        CHAR_SIGN,
        CHAR_BLANK,
        CHAR_ILLEGAL
    };
    CharType toCharType(const char& ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_BLANK;
        } else {
            return CHAR_ILLEGAL;
        }
    }
    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL,
             {{CHAR_NUMBER, STATE_INT},
              {CHAR_SIGN, STATE_SIGN},
              {CHAR_POINT, STATE_POINT_LEFT_NO},
              {CHAR_BLANK, STATE_INITIAL}}},
            {STATE_SIGN,
             {{CHAR_NUMBER, STATE_INT},
              {CHAR_POINT, STATE_POINT_LEFT_NO}}},
            {STATE_INT,
             {{CHAR_NUMBER, STATE_INT},
              {CHAR_POINT, STATE_POINT_LEFT_YES},
              {CHAR_EXP, STATE_EXP},
              {CHAR_BLANK, STATE_END_BLANK}}},
            {STATE_POINT_LEFT_YES,
             {{CHAR_EXP, STATE_EXP},
              {CHAR_NUMBER, STATE_FRACTION},
              {CHAR_BLANK, STATE_END_BLANK}}},
            {STATE_FRACTION,
             {{CHAR_EXP, STATE_EXP},
              {CHAR_NUMBER, STATE_FRACTION},
              {CHAR_BLANK, STATE_END_BLANK}}},
            {STATE_EXP,
             {{CHAR_NUMBER, STATE_EXP_NUMBER},
              {CHAR_SIGN, STATE_EXP_SIGN}}},
            {STATE_EXP_SIGN,
             {{CHAR_NUMBER, STATE_EXP_NUMBER}}},
            {STATE_EXP_NUMBER,
             {{CHAR_NUMBER, STATE_EXP_NUMBER},
              {CHAR_BLANK, STATE_END_BLANK}}},
            {STATE_POINT_LEFT_NO,
             {{CHAR_NUMBER, STATE_FRACTION}}},
            {STATE_END_BLANK,
             {{CHAR_BLANK, STATE_END_BLANK}}}};
        State curState = STATE_INITIAL;
        for (const char& ch : s) {
            if (!transfer[curState].count(toCharType(ch))) {
                return false;
            }
            curState = transfer[curState][toCharType(ch)];
        }
        return curState == STATE_INT || curState == STATE_POINT_LEFT_YES ||
               curState == STATE_FRACTION || curState == STATE_EXP_NUMBER || curState == STATE_END_BLANK;
    }
};
int main() {

    system("pause");
    return 0;
}