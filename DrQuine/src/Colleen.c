#include <stdio.h>
/*
    comment
*/
void nothing(void){}
int main(){char*s="#include <stdio.h>%1$c/*%1$c    comment%1$c*/%1$cvoid nothing(void){}%1$cint main(){char*s=%2$c%3$s%2$c;nothing();printf(s,10,34,s);%1$c/*%1$c    toto%1$c*/%1$c}%1$c";nothing();printf(s,10,34,s);
/*
    toto
*/
}
