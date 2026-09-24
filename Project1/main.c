#include <stdio.h>
#include <stdlib.h>

int main()
{ //dataType and variable name
    char userName[50];

    //user   to input name
    printf("Please enter your username\n");
    scanf("%s", userName);
    printf("Hello %s", userName );


    return 0;
}
