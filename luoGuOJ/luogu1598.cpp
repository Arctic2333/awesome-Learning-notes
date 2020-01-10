/*题目描述
 *题目描述
 *写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过100个字符），然后用柱状图输出每个字符在输入文件中出现的次数。
 * 严格地按照输出样例来安排你的输出格式。

输入格式
四行字符，由大写字母组成，每行不超过100个字符

输出格式
由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。在任何一行末尾不要打印不需要的多余空格。不要打印任何空行。
  
  题目来源：https://www.luogu.com.cn/problem/P1598

  模拟 + 打印
*/
#include <stdio.h>

#include <string.h>

int count[26];

int main() {
    char a[100];
    for (int i = 0; i < 4; i++) {
        gets(a);
        int n = strlen(a);
        for (int j = 0; j < n; j++)
            if (a[j] >= 'A' && a[j] <= 'Z')
                count[a[j] - 'A']++;
    }
    int max_len = 0;
    for (int i = 0; i < 26; i++)
        if (count[i] >= max_len)
            max_len = count[i];

    for (int i = max_len; i > 0; i--) {
        for (int j = 0; j < 26; j++)
            if (count[j] >= i)
                printf("* ");
            else
                printf("  ");
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        printf("%c ", i + 'A');
    }

}