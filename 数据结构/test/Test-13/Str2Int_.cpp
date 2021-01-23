#include "stdio.h"
#include "conio.h"
#include "string.h"
int StrToInt(char *s)
{	char ss[32];
	if(strlen(s)==1) return s[0]-'0';
//************************************************
	printf("%c",*s);
	StrToInt(s+1);


//=================================================
}

int main()
{	char t[32];
//	freopen("Str2Int_.in", "r", stdin);
//	freopen("Str2Int_.out", "w", stdout);
	gets(t);
	printf("%d", StrToInt(t));
	return 0;
}
