#include <stdio.h>
#include <iostream>
using namespace std;

int m, n;   // ��ʾ�Թ����������������
int **maze; // ָ���Թ������ָ��

typedef struct node
{
  int ipos, jpos;
  int direct[8];
  struct node *next;
} node_type; // ̽��ջ�������

typedef struct postp
{
  int ipos, jpos;
  struct postp *next;
} pos_type; // ·��ջ�������

node_type *top; // ָ��̽��ջ��ջ��ָ��

pos_type *pos_top; // ָ��·��ջ��ջ��ָ��

void init(int x0, int y0) // ��ʼ��̽��ջ�ף����������������Χ8����״̬
{
  top = new node_type;
  top->ipos = x0;
  top->jpos = y0;
  top->direct[0] = maze[x0 - 1][y0 - 1];
  top->direct[1] = maze[x0 - 1][y0];
  top->direct[2] = maze[x0 - 1][y0 + 1];
  top->direct[3] = maze[x0][y0 - 1];
  top->direct[4] = maze[x0][y0 + 1];
  top->direct[5] = maze[x0 + 1][y0 - 1];
  top->direct[6] = maze[x0 + 1][y0];
  top->direct[7] = maze[x0 + 1][y0 + 1];
  top->next = NULL;
}

void check_cycle(int ii, int jj, node_type *newp) // �����̤������Χ��ĳһ���Ƿ�����·����
{
  node_type *p = top;
  while ((p != NULL) && (!((p->ipos == ii) && (p->jpos == jj))))
    p = p->next;
  if (p != NULL)
    switch (newp->ipos - ii)
    {
    case 1:
      switch (newp->jpos - jj)
      {
      case 1:
        newp->direct[0] = 0;
        break;
      case 0:
        newp->direct[1] = 0;
        break;
      case -1:
        newp->direct[2] = 0;
      }
      break;
    case 0:
      switch (newp->jpos - jj)
      {
      case 1:
        newp->direct[3] = 0;
        break;
      case -1:
        newp->direct[4] = 0;
      }
      break;
    case -1:
      switch (newp->jpos - jj)
      {
      case 1:
        newp->direct[5] = 0;
        break;
      case 0:
        newp->direct[6] = 0;
        break;
      case -1:
        newp->direct[7] = 0;
      }
    }
}

void push(int ii, int jj) // ̽���е�һ��̤������ջ��
{
  node_type *p;
  p = new node_type;
  p->ipos = ii;
  p->jpos = jj;
  p->direct[0] = maze[ii - 1][jj - 1];
  p->direct[1] = maze[ii - 1][jj];
  p->direct[2] = maze[ii - 1][jj + 1];
  p->direct[3] = maze[ii][jj - 1];
  p->direct[4] = maze[ii][jj + 1];
  p->direct[5] = maze[ii + 1][jj - 1];
  p->direct[6] = maze[ii + 1][jj];
  p->direct[7] = maze[ii + 1][jj + 1];
  if (p->direct[0])
    check_cycle(ii - 1, jj - 1, p);
  if (p->direct[1])
    check_cycle(ii - 1, jj, p);
  if (p->direct[2])
    check_cycle(ii - 1, jj + 1, p);
  if (p->direct[3])
    check_cycle(ii, jj - 1, p);
  if (p->direct[4])
    check_cycle(ii, jj + 1, p);
  if (p->direct[5])
    check_cycle(ii + 1, jj - 1, p);
  if (p->direct[6])
    check_cycle(ii + 1, jj, p);
  if (p->direct[7])
    check_cycle(ii + 1, jj + 1, p);
  p->next = top;
  top = p;
}

void pop() // ̽���еĻ��ˣ�һ�γ�ջ��
{
  node_type *p;
  p = top;
  top = p->next;
  delete p;
}

void show_maze() // ��ʾ�Թ�����
{
  int i, j;
  cout << "A maze shown as below: \n";
  for (i = 0; i < m; i++)
  {
    cout << "     ";
    for (j = 0; j < n; j++)
      cout << maze[i][j] << ' ';
    cout << endl;
  }
}

void show_pathway() // ������ʾ�߳��Թ���·�� �Ƚ�̽��ջ ��� ·��ջ
{
  //************************************************
  pos_top = NULL;
  while (top != NULL)
  {
    pos_type *p = new pos_type;
    p->ipos = top->ipos;
    p->jpos = top->jpos;
    p->next = pos_top;
    pos_top = p;
    top = top->next;
  }
  while (pos_top)
  {
    cout << "(" << pos_top->ipos << "," << pos_top->jpos << ")";
    pos_top = pos_top->next;
    if (pos_top)
    {
      cout << " ";
    }
  }
  //================================================
  cout << endl;
}

int main()
{
  int i, j;
  freopen("MazePath.in", "r", stdin);
  freopen("MazePath.out", "w", stdout);
  cin >> m;
  cin >> n;
  maze = new int *[m];
  for (i = 0; i < m; i++)
    maze[i] = new int[n];
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      cin >> maze[i][j];
  show_maze();
  init(1, 1);
  //************************************************
  //�����Ĺ���
  int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  while (!(top->ipos == m - 2 && top->jpos == n - 2))
  {
    bool ifPush = false;
    for (int i = 0; i < 8; i++)
      if (top->direct[i])
      {
        ifPush = true;
        top->direct[i] = 0;
        push(top->ipos + dirx[i], top->jpos + diry[i]);
        break;
      }

    if (!ifPush)
    {
      if (top->ipos == 1 && top->jpos == 1)
      {
        pop();
        break;
      }
      pop();
    }
  }

  //================================================
  if (top != NULL)
  {
    cout << "Pathway to get out off the maze: \n";
    show_pathway();
  }
  else
    cout << "No pathway\n";
  return 1;
}
