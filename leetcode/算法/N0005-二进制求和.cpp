#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>

// std::string addBinary(std::string a, std::string b) {
//     bool over = false;

//     std::string ans;

//     int i, j;
//     for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
//         if (a[i] == '0') {
//             if (b[j] == '0') {
//                 ans.insert(ans.begin(), over ? '1' : '0');
//                 over = false;
//             } else {
//                 ans.insert(ans.begin(), over ? '0' : '1');
//             }
//         } else {
//             if (b[j] == '0') {
//                 ans.insert(ans.begin(), over ? '0' : '1');
//             } else {
//                 ans.insert(ans.begin(), over ? '1' : '0');
//                 over = true;
//             }
//         }
//     }

//     while (i >= 0) {
//         if (a[i] == '1') {
//             ans.insert(ans.begin(), over ? '0' : '1');
//         } else {
//             ans.insert(ans.begin(), over ? '1' : '0');
//             over = false;
//         }
//         i--;
//     }

//     while (j >= 0) {
//         if (b[j] == '1') {
//             ans.insert(ans.begin(), over ? '0' : '1');
//         } else {
//             ans.insert(ans.begin(), over ? '1' : '0');
//             over = false;
//         }
//         j--;
//     }

//     if (over)
//         ans.insert(ans.begin(), '1');

//     return ans;
// }


// * 简洁写法
std::string addBinary(std::string a, std::string b) {
    std::string ans;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    // * carry 表示当前位累计出现 1 的个数
    // * carry 进到上一位需要除 2
    int n = std::max(a.size(), b.size()), carry = 0;
    for (size_t i = 0; i < n; ++i) {
        carry += i < a.size() ? (a.at(i) == '1') : 0;
        carry += i < b.size() ? (b.at(i) == '1') : 0;
        ans.push_back((carry % 2) ? '1' : '0');
        carry /= 2;
    }

    if (carry) {
        ans.push_back('1');
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    assert(addBinary("010", "1") == "011");
    assert(addBinary("011", "1") == "100");
    assert(addBinary("111", "1") == "1000");
    assert(addBinary("10", "10") == "100");

    return 0;
}