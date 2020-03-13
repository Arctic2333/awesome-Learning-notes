/*
 * @Author: Arctic
 * @Date: 2020-03-13 17:32:57
 * @Last Modified by: Arctic
 * @Last Modified time: 2020-03-13 17:42:56
 */
// 线性表顺序储存结构
/* InitList(*L)
 * ListEmpty(L)
 * ClearList(*L)
 * GetELem(L,i,*e)
 * LocateElem(L,e)
 * ListInsert(*L,i,e)
 * ListDelete(*L,i,*e)
 * ListLength(L)
 */
#include <stdio.h>
#define maxlength 20  // 存储空间初始分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct {
  ElemType data[maxlength];  // 数组存储数据
  int length;                // 当前长度
} Sqlist;
void InitList(Sqlist L) {  // 初始化
  for (register int i = 0; i < maxlength; i++) {
    L.data[i] = 0;
  }
  L.length = 0;
}
void ClearList(Sqlist L) {  // 清空
  for (register int i = 0; i < maxlength; i++) {
    L.data[i] = 0;
  }
  L.length = 0;
}
Status ListEmpty(Sqlist L) {  // 判表空
  if (L.length == 0) {
    return TRUE;
  }
  return FALSE;
}
Status GetElem(Sqlist L, int i, ElemType *e) {  // 取元素
  if (ListEmpty(L) == 1 || i < 1 || i > L.length) {
    return ERROR;
  }
  *e = L.data[i - 1];
  return OK;
}
Status LocateElem(Sqlist L, ElemType e) {  // 定位元素
  if (ListEmpty(L) == 1) {
    return ERROR;
  }
  for (register int i = 0; i < L.length; i++) {
    if (L.data[i] == e) {
      return i + 1;  // 位置从 1 开始
    }
  }
  return FALSE;  // 没找到或表空就一定返回 0
}
Status ListInsert(Sqlist *L, int i, ElemType e) {
  if (L->length == maxlength) {  // 表满
    return ERROR;
  }
  if (i < 1 || i > L->length + 1) {
    return ERROR;  // i 的位置是否合理
  }
  if (i <= L->length) {  // 将插入的元素的位置后的元素后移
    for (register int y = L->length - 1; y >= i - 1; y--) {
      L->data[y + 1] = L->data[y];
    }
  }
  L->data[i - 1] = e;  // 将新元素插入
  L->length++;
  return OK;
}
Status ListDelete(Sqlist *L, int i, ElemType *e) {
  if (L->length == 0) {
    return ERROR;
  }
  if (i < 1 || i > L->length) {
    return ERROR;
  }
  *e = L->data[i - 1];
  if (i <
      L->length) {  // 判断是不是最后一个元素，不是每一个前移一位，是的话直接length-1，就相当于删除了。
    for (register int y = i; y < L->length; y++) {
      L->data[y - 1] = L->data[y];
    }
  }
  L->length--;
  return OK;
}
