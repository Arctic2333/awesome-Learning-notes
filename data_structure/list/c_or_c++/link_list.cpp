/*
 * @Author: Arctic
 * @Date: 2020-03-14 14:27:21
 * @Last Modified by: Arctic
 * @Last Modified time: 2020-03-14 15:20:10
 *
 * 线性表的链式存储结构
 * CreateListHead(*L)
 * CreateListTail(*L)
 * ListEmpty(L)
 * ClearList(*L)
 * GetELem(L,i,*e)
 * LocateElem(L,e)
 * ListInsert(*L,i,e)
 * ListDelete(*L,i,*e)
 * ListLength(L)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;
typedef struct Node *LinkList;  // 指针型
// 产生n个随机数据建立表
void CreateListHead(LinkList *L, int n) {  // 头插法
  LinkList p;
  srand(time(0));  // 初始化随机数种子
  *L = (LinkList)malloc(sizeof(
      Node));  // 二级指针 指向指针的指针  这句和 直接new差不多  初始化单链表
  (*L)->next = NULL;  //*L 就是一级指针
  for (register int i = 0; i < n; i++) {
    p = (LinkList)malloc(sizeof(Node));
    p->data = rand() % 100 + 1;  // 保证随机数在100以内
    p->next = (*L)->next;
    (*L)->next = p;
  }
}
void CreateListTail(LinkList *L, int n) {  // 尾插法
  LinkList p, q;
  srand(time(0));
  *L = (LinkList)malloc(sizeof(Node));
  (*L)->next = NULL;
  q = (*L);  // q用来指向当前结点
  for (register int i = 0; i < n; i++) {
    p = (LinkList)malloc(sizeof(Node));
    p->data = rand() % 100 + 1;
    q->next = p;
    q = p;
  }
  q->next = NULL;
}
Status ListEmpty(LinkList L) {
  if (L->next == NULL) {
    return OK;
  }
  return FALSE;
}
Status GetElem(LinkList L, int i, ElemType *e) {
  int j = 1;   // 计数器
  LinkList p;  // 往后移的指针
  p = L->next;
  while (p && j < i) {  // 核心思想 “工作指针往后移”
    p = p->next;
    ++j;
  }
  if (!p || j > i) return ERROR;
  *e = p->data;
  return OK;
}
Status ListInsert(LinkList *L, int i, ElemType e) {
  int j = 1;
  LinkList p, s;
  p = (*L);
  while (p && j < i) {
    p = p->next;
    ++j;
  }
  if (!p || j > i) return ERROR;
  s = (LinkList)malloc(sizeof(Node));  // LinkList *s = new LinkList;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}
