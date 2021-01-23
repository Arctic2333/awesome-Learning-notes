/*
 * @Author: Arctic
 * @Date: 2020-03-15 11:59:13
 * @Last Modified by: Arctic
 * @Last Modified time: 2020-03-15 12:08:15
 */
// 静态链表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct {
  ElemType data;
  int cur;  // 游标指示下格的位置
} Componet, StaticLinkList[MAXSIZE];
Status InitList(StaticLinkList space) {
  for (register int i = 0; i < MAXSIZE - 1; i++) {
    space[i].cur = i + 1;
  }
  space[MAXSIZE - 1].cur = 0;
  return OK;
}
int Malloc_SLL(StaticLinkList space) {  // 返回分配的结点的下标
  int i = space[0].cur;  // 第一个元素的CUR的值就是备用空闲的下标
  if (space[0].cur)
    space[0].cur =
        space[i].cur;  // 把被分配的分量的下一个分量的下标存入第一个元素的下标
  return i;
}
int ListLength(StaticLinkList L) {
  int j = 0;
  int i = L[MAXSIZE - 1].cur;
  while (i) {
    i = L[i].cur;
    j++;
  }
  return j;
}
Status ListInsert(StaticLinkList L, int i, ElemType e) {  // 核心就是改游标
  int j, k, l;
  k = MAXSIZE - 1;  //最后一个元素的下标
  if (i < 1 || i > ListLength(L) + 1) return ERROR;
  j = Malloc_SLL(L);
  if (j) {
    L[i].data = e;
    for (l = 1; l <= i; l++) k = L[k].cur;  // 找到第i个元素之前的位置
    L[j].cur = L[k].cur;  // 把第i个元素之前的cur赋值给新元素的cur
    L[k].cur = j;  // 把新元素的下标赋值给第i个元素之前的cur
    return OK;
  }
  return ERROR;
}
void Free_SSL(StaticLinkList space, int k) {
  space[k].cur = space[0].cur;
  space[0].cur = k;  // 把空闲结点k回收入备用链表
}
Status ListDelete(StaticLinkList L, int i) {
  int j, k;
  if (i < 1 || i > ListLength(L)) return ERROR;
  k = MAXSIZE - 1;
  for (j = 1; j <= i - 1; j++) k = L[k].cur;
  j = L[k].cur;
  L[k].cur = L[j].cur;
  Free_SSL(L, j);
  return OK;
}
