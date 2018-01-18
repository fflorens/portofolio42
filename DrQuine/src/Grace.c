#include <stdio.h>
/*
    comment
*/
#define ONE
#define TWO
#define THREE(X) int main(){FILE*f=fopen("Grace_kid.c","w");char*s="#include <stdio.h>%1$c/*%1$c    comment%1$c*/%1$c#define ONE%1$c#define TWO%1$c#define THREE(X) int main(){FILE*f=fopen(%2$cGrace_kid.c%2$c,%2$cw%2$c);char*s=%2$c%3$s%2$c;if(!f)return 1;fprintf(f,s,(X),34,s);}%1$cTHREE(10)%1$c";if(!f)return 1;fprintf(f,s,(X),34,s);}
THREE(10)
