#include <stdio.h>
#include <stdbool.h>
void write_int(int num)
{
    printf("%d", num);
    fflush(stdout);
    return;
}
void write_real(double num)
{
    printf("%lf", num);
    fflush(stdout);
    return;
}
void wirte_char(char ch)
{
    printf("%c", ch);
    fflush(stdout);
    return;
}
void write_boolean(bool num)
{
    if (num == true)
        printf("TRUE");
    else
        printf("FALSE");
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