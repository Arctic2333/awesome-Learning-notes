#include "stdio.h"

typedef struct node {
  int digit;
  struct node *next;
} datanode;  // ������������

datanode *init_link()  // ��ʼ��������
{
  datanode *h;
  h = new datanode;
  h->next = NULL;
  return h;
}

void free(datanode *h)  // �ͷŵ�����
{
  datanode *p = h;
  do {
    h = h->next;
    delete p;
    p = h;
  } while (p != NULL);
}

void input(datanode *h)  // ����߾�������
{
  datanode *p, *q = h;
  char ch;
  int stack[256], top = -1;
  scanf("%c", &ch);
  while (ch != '\n') {
    stack[++top] = ch - '0';
    scanf("%c", &ch);
  }
  while (top != -1) {
    p = new datanode;
    p->digit = stack[top--];
    q->next = p;
    q = p;
  }
  p->next = NULL;
}

void output(datanode *h)  // ����߾�������
{
  //************************************************
  int stack[256], top = -1;
  datanode *q = h->next;
  while (q) {
    stack[++top] = q->digit;
    q = q->next;
  }
  while (top != -1) {
    printf("%d", stack[top--]);
  }
  //=================================================
}

void plus(datanode *a, datanode *b,
          datanode *c)  // ��a��b����ͷָ��ĵ������еĸ߾��������ĺ�
                        // �ʹ����cΪͷָ��ĵ�������
{
  //************************************************
  int t = 0, ad = 0;
  datanode *pa = a->next;
  datanode *pb = b->next;
  datanode *pc = c;
  while (pa && pb) {
    t = pa->digit + pb->digit + ad;
    ad = 0;
    if (t >= 10) {
      t -= 10;
      ad++;
    }
    datanode *q = new datanode;
    q ->digit = t;
    pc->next = q;
    pc = q;
    pa = pa->next;
    pb = pb->next;
  }
  while(pa){
    t = pa->digit+ad;
    ad = 0;
    if(t >= 10){
      t -= 10;
      ad++;
    }
    datanode *q = new datanode;
    q ->digit = t;
    pc ->next = q;
    pc = q;
    pa = pa->next;
  }
  while(pb){
    t = pb->digit+ad;
    ad = 0;
    if(t >= 10){
      t -= 10;
      ad++;
    }
    datanode *q = new datanode;
    q ->digit = t;
    pc ->next = q;
    pc = q;
    pb = pb->next;
  }
  if(ad){
    datanode *q = new datanode;
    q->digit = ad;
    pc->next = q;
    pc = q;
  }
  pc ->next = NULL;
  //=================================================
}

int main() {
  char s1[256], s2[256];
  datanode *d1 = NULL, *d2 = NULL, *d3 = NULL;
  freopen("BigDataPlus.in", "r", stdin);
  freopen("BigDataPlus.out", "w", stdout);
  d1 = init_link();
  input(d1);
  d2 = init_link();
  input(d2);
  d3 = init_link();
  plus(d1, d2, d3);
  output(d3);
  free(d1);
  free(d2);
  free(d3);
  return 0;
}
