/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** little part of printf with 5 flags
*/

#include "shell.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
    my_putchar(str[i]);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
    } else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / i) >= 10)
        i *= 10;
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return 0;
}

int case_percent(va_list args, const char y)
{
    switch (y) {
    case 's':
    my_putstr(va_arg(args, char *));
    break;
    case '%':
    my_putchar('%');
    break;
    case 'c':
    my_putchar(va_arg(args, int));
    break;
    case 'd':
    my_put_nbr(va_arg(args, int));
    break;
    case 'i':
    my_put_nbr(va_arg(args, int));
    break;
    }
    return 0;
}

int mini_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
        case_percent(args, str[i + 1]);
        i++;
        } else {
        my_putchar(str[i]);
        }
    }
    va_end(args);
    return 0;
}
