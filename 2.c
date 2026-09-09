#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = strlen(text) - 1; i >= 0; i--)
    {
        printf("%c", text[i]);
    }
    printf("\n");
}