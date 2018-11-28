#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int palindrome(char* c, int longueur){
    if (longueur <= 1)
        return 1;
    if (c[0] != c[longueur - 1])
        return 0;
return palindrome(c + 1, longueur - 2);
}
int main(){
int p = palindrome("UNROCCORNU",10);
printf("p %d", p);
}