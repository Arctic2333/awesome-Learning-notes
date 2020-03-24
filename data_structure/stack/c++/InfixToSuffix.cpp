#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  string str = "1*(2+3/4)-5*6";
  stack<char> stack;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '+' || str[i] == '-') {
      if (stack.empty() || stack.top() == '(') {
        stack.push(str[i]);
      } else {
        while (!stack.empty() && (stack.top() == '*' || stack.top() == '/' ||
                                  stack.top() == '+' || stack.top() == '-')) {
          char temp = stack.top();
          stack.pop();
          cout << temp;
        }
        stack.push(str[i]);
      }
    } else if (str[i] == '*' || str[i] == '/') {
      if (stack.empty() || stack.top() == '+' || stack.top() == '-' ||
              stack.top() == '(') {
        stack.push(str[i]);
      } else {
        while (!stack.empty() && (stack.top() == '/' || stack.top() == '*')) {
          char temp = stack.top();
          stack.pop();
          cout << temp;
        }
        stack.push(str[i]);
      }
    } else if (str[i] == '(') {
      stack.push(str[i]);
    } else if (str[i] == ')') {
      char temp = stack.top();
      while (temp != '(') {
        stack.pop();
        cout << temp;
        temp = stack.top();
      }

    } else {
      cout << str[i];
    }
  }
  if (!stack.empty()) {
    while (!stack.empty()) {
      char temp = stack.top();
      stack.pop();
      cout << temp;
    }
  }
  return 0;
}