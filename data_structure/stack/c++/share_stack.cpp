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
typedef struct {
  SElemType data[MAXSIZE];
  int top1;
  int top2;
} SqDoubleStack;
Status Push(SqDoubleStack *s, SElemType e, int stackNumber) {
  if (s->top1 + 1 == s->top2) {
    return ERROR;
  }
  if (stackNumber == 1) {
    s->data[++s->top1] = e;
  }
  if (stackNumber == 2) {
    s->data[--s->top2] = e;
  }
  return OK;
}
Status Pop(SqDoubleStack *s, SElemType *e, int stackNumber) {
  if (stackNumber == 1) {
    if (s->top1 == -1) return ERROR;
    *e = s->data[s->top1--];
  } else if (stackNumber == 2) {
    if (s->top2 == MAXSIZE) return ERROR;
    *e = s->data[s->top2++];
  }
  return OK;
}