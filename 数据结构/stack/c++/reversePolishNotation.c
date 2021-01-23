#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int top, a[1000];

void push(int x) {
    /* top加一之后将元素插入
     * top所☞的位置
     */
    a[++top] = x;
}

int pop() {
    top--;
    // 返回top所指的值
    return a[top + 1];
}

int main() {
    int a, b;
    top = 0;
    char s[100];
    while (scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            a = pop();
            b = pop();
            push(a + b);
        } else if (s[0] == '-') {
            b = pop();
            a = pop();
            push(b - a);
        } else if (s[0] == '*') {
            a = pop();
            b = pop();
            push(a * b);
        } else {
            push(atoi(s));
        }
    }

    printf("%d\n", pop());

    return 0;
}
