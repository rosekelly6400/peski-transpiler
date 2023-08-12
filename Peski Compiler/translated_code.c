#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> 
bool fizzbuzz( int limit )
{
        int a = 1;
        bool found = false;
        while(a<=limit)
{
        if(a%3==0)
{
                printf("fizz");
}
        if(a%5==0)
{
                printf("buzz");
}
        printf("\n");
        a++;
}
        if(limit>=3)
{
                found=true;
}
        else
{
        printf("none found");
}
        return found;
}
int main(int argc, char *argv[])
{
        fizzbuzz(15);
}
