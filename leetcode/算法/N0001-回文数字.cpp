#include <assert.h>

#include <string>

/* C1
 * 执行用时：
 * 8 ms, 在所有 C++ 提交中击败了 77.21% 的用户
 * 内存消耗：
 * 5.8 MB, 在所有 C++ 提交中击败了 49.84% 的用户
 */
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    std::string strVal = std::to_string(x);

    int left = 0, right = strVal.size() - 1;
    while (left < right) {
        if (strVal[left] != strVal[right])
            return false;
        left++;
        right--;
    }

    return true;
}

/**
 * @brief C2 不使用额外空间
 *
 */
bool isPalindrome(int x) {
    // 特殊情况：
    // 如上所述，当 x < 0 时，x 不是回文数。
    // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
    // 则其第一位数字也应该是 0
    // 只有 0 满足这一属性
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x =
    // 12，revertedNumber = 123，
    // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return x == revertedNumber || x == revertedNumber / 10;
}

int main() {
    assert(false == isPalindrome(-111));
    assert(true == isPalindrome(111));
    assert(true == isPalindrome(121));
    assert(true == isPalindrome(9999));

    return 0;
}