#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    char s[100];
    char sen[100];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%c", &c);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%c\n%s\n%s\n", c, s, sen);
    return 0;
}


