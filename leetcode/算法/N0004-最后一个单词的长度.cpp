#include <assert.h>

#include <string>

int lengthOfLastWord(std::string s) {
    int i = 0;
    for (i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ')
            continue;
        break;
    }

    int ans = 0;
    for (; i >= 0; i--) {
        if (s[i] == ' ')
            break;
        ans++;
    }

    return ans;
}

int main()  {
    std::string strTest1 = "hell0 world!";
    std::string strTest2 = " hello world ";
    std::string strTest3 = " hel  llo wor    ld  ";
    std::string strTest4 = "";
    std::string strTest5 = "    ";
    
    assert(lengthOfLastWord(strTest1) == 6);
    assert(lengthOfLastWord(strTest2) == 5);
    assert(lengthOfLastWord(strTest3) == 2);
    assert(lengthOfLastWord(strTest4) == 0);
    assert(lengthOfLastWord(strTest5) == 0);

    return 0;
}
