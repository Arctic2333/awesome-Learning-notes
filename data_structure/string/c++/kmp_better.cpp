#include <cstring>
#include <iostream>
using namespace std;
char a[257], b[257];
void get_next(char a[], int *next) {
  int i, j;
  int len = strlen(a + 1);
  i = 1;
  j = 0;
  next[1] = 0;
  while (i <= len) {
    if (j == 0 || a[i] == a[j]) {
      i++;
      j++;
      if(a[i]!=a[j]){
        next[i] = j;
      }else{
        next[i] = next[j];
      }
    } else {
      j = next[j];
    }
  }
}

int main() {
  scanf("%s%s", a + 1, b + 1);
  int len1 = strlen(a + 1);
  int len2 = strlen(b + 1);
  int next[257];
  get_next(b, next);
  //============================ KMP核心配对
  int i = 1, j = 1;
  while (i <= len1 && j <= len2) {
    if(j == 0 || a[i]==b[j]){
      ++i;
      ++j;
    }else{
      j = next[j];
    }
    if(j - 1 == len2){
    cout << i - len2 << endl;
    i--;
    j=1;
    }
  }
  //============================
}