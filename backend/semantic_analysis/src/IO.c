#include <stdio.h>
#include <stdbool.h>
void write_int(int num)
{
    printf("%d\n", num);
    fflush(stdout);
    return;
}
void write_real(double num)
{
    printf("%lf\n", num);
    fflush(stdout);
    return;
}
void write_char(char ch)
{
    printf("%c\n", ch);
    fflush(stdout);
    return;
}
void write_boolean(bool num)
{
    if (num == true)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    fflush(stdout);
    return;
}

int read_int()
{
    int num;
    scanf("%d", &num);
    return num;
}
float read_real()
{
    double num;
    scanf("%lf", &num);
    return num;
}
char read_char()
{
    char ch;
    scanf("%c", &ch);
    return ch;
}
bool read_boolean()
{
    int num;
    scanf("%d", &num);
    return num;
}
