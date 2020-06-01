#include "stdio.h"
#include "conio.h"
#include "string.h"
int StrToInt(char *s)
{
//************************************************
	int v=0;
	
	while(*s!='\0')
	{
		int t=*s-'0';
		v=10*v+t;
		s++;	
	}
	return v;


//=================================================
}

int main()
{	char t[32];
//	freopen("Str2Int.in", "r", stdin);
//	freopen("Str2Int.out", "w", stdout);
	gets(t);
	printf("%d", StrToInt(t));
	return 0;
}
