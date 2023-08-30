#include "ded.h"

int compare_doubles (double k, double n)//TODO make compare_doubles function.
{
    double const limit = 1e-6;
    return fabs(k - n) < limit;
}

int get_coeff (double* a, double* b, double* c)
{
    printf ("Введите коэффициенты квадратного уравнения:\n");
    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        printf ("Введены некорректные значения:(\n");
        break;
    }
    return 0;
}

void solve_quadratic_equation (double a, double b, double c, double *x1, double *x2, int *nRoots)
{
    if (compare_doubles(0, a))
    {
        solve_linear_equation (b, c, nRoots, x1);
    }
    else if (compare_doubles(0, b))
    {
        if (compare_doubles(0, c))
        {
            *x1 = 0;
            *nRoots = ONE_ROOT;
        }
        else
        {
            if (c > 0)
            {
                *nRoots = ZERO_ROOTS;
            }
            else
            {
                *x1 = sqrt(-c) / a;
                *x2 = -sqrt(-c) / a;
                *nRoots = TWO_ROOTS;
            }
        }
    }
    else
    {
        if (compare_doubles(0, c))
        {
            *x1 = 0;
            *x2 = -b / a;
            *nRoots = TWO_ROOTS;
        }
        else
        {
            double D = 0;
            D = b * b - 4 * a * c;
            if (D < 0)
            {
                *nRoots = ZERO_ROOTS;
            }
            else if (compare_doubles(0, D))
            {
                *x1 = -b / 2 * a;
                *nRoots = ONE_ROOT;
            }
            else
            {
                *x1 = (-b - sqrt(D)) / (2 * a);
                *x2 = (-b + sqrt(D)) / (2 * a);
                *nRoots = TWO_ROOTS;;
            }
        }
    }
}
void solve_linear_equation (double b1, double c1, int *nRoots, double *x1)
{
    int x;
    if (compare_doubles(0, b1))
    {
        if (compare_doubles(0, c1))
        {
            *nRoots = INF_ROOTS;
        }
        else
        {
            *nRoots = ZERO_ROOTS;
        }
    }
    else
    {
        *x1 = -c1 / b1;
        *nRoots = ONE_ROOT;
    }
}
void print_root (double x1, double x2, int nRoots)
{
    switch (nRoots)
    {
    case ZERO_ROOTS:
        printf ("Уравнение не имеет корней.\n");
        break;
    case ONE_ROOT:
        printf ("Корень уравнения равен %.2lf\n", x1);
        break;
    case TWO_ROOTS:
        printf ("Корни уравнения %.2lf и %.2lf.\n", x1, x2);
        break;
    case INF_ROOTS:
        printf ("Решением является любое действительное число.\n");
    default:
        printf ("Что-то сломалось:(\n");
    }
}