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
  int top;  // 栈顶指针
} SqStack;
Status Push(SqStack *s, SElemType e) {
  if (s->top == MAXSIZE - 1) {
    return ERROR;
  }
  s->top++;
  s->data[s->top] = e;
  return OK;
}
Status Pop(SqStack *s, SElemType *e) {
  if (s->top == -1) {
    return ERROR;
  }
  *e = s->data[s->top];
  s->top--;
  return OK;
}
Status GetTop(SqStack *s, SElemType *e){
  if(s->top== -1){
    return ERROR;
  } 
  *e = s->data[s->top];
  return OK;
}