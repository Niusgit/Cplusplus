#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>

std::string convertToTitle(int columnNumber) {
    std::string ans;
    while (columnNumber) {
        int residual = columnNumber % 26;
        if (residual) {
            ans.insert(ans.begin(), residual + 'A' - 1);
            columnNumber -= residual;
        } else {
            ans.insert(ans.begin(), 'Z');
            columnNumber -= 26;
        }

        columnNumber /= 26;
    }

    return ans;
}

// * 简洁写法
// std::string convertToTitle(int columnNumber) {
//     std::string ans;
//     while (columnNumber) {
//         int residual = (columnNumber - 1) % 26;
//         ans.push_back(residual + 'A');

//         columnNumber -= residual + 1;
//         columnNumber /= 26;
//     }

//     std::reverse(ans.begin(), ans.end());
//     return ans;
// }

// * 更简洁写法: 26进制, 起始值为 1, 则-1即可直接取模
// string convertToTitle(int columnNumber) {
//     string ans;
//     while (columnNumber > 0) {
//         --columnNumber;
//         ans += columnNumber % 26 + 'A';
//         columnNumber /= 26;
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

int main() {
    assert(convertToTitle(701) == "ZY");
    assert(convertToTitle(2147483647) == "FXSHRXW");

    return 0;
}