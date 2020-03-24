#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int SElemType;
typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;
typedef struct LinkStack {
  LinkStackPtr top;
  int count;
} LinkStack;
Status Push(LinkStack *s, SElemType e) {
  LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));
  q->data = e;
  q->next = s->top;
  s->top = q;
  s->count++;
  return OK;
}
Status Pop(LinkStack *s, SElemType *e) {
  LinkStackPtr p;
  if (StackEmpty(s)) {
    return ERROR;
  }
  *e = s->top->data;
  p = s->top;
  s->top = s->top->next;
  free(p);
  s->count--;
  return OK;
}
Status StackEmpty(LinkStack *s) {
  if (s->top->next == NULL) {
    return OK;
  }
  return ERROR;
}