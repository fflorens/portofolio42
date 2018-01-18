#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
int i=5;
char f[100],c[100],*s="#include <stdio.h>%1$c#include <string.h>%1$c#include <stdlib.h>%1$cint main(){%1$cint i=%2$d;%1$cchar f[100],c[100],*s=%3$c%4$s%3$c;if(i<0)return 0;sprintf(f,%3$cSully_%%d.c%3$c,i--);FILE*p=fopen(f,%3$cw%3$c);if(!p)return 1;fprintf(p,s,10,i,34,s);fclose(p);sprintf(c,%3$cclang -Wall -Werror -Wextra -o %%.*s %%s%3$c,(int)strlen(f)-2,f,f);system(c);sprintf(c,%3$c./%%.*s%3$c,(int)strlen(f)-2,f);system(c);}%1$c";if(i<0)return 0;sprintf(f,"Sully_%d.c",i--);FILE*p=fopen(f,"w");if(!p)return 1;fprintf(p,s,10,i,34,s);fclose(p);sprintf(c,"clang -Wall -Werror -Wextra -o %.*s %s",(int)strlen(f)-2,f,f);system(c);sprintf(c,"./%.*s",(int)strlen(f)-2,f);system(c);}
