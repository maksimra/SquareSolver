#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//const int NTESTS = 5;

enum count_of_roots  //доделать тему с ней.
{
    ZERO_ROOTS  = 0, 
    ONE_ROOT    = 1, 
    TWO_ROOTS   = 2,
    INF_ROOTS   = 3 //большим 
};
//поделить на файлы
struct info_for_tests 
{
    double a, b, c, x1, x2;
    int nRoots;
}; //допилить
/*
const struct info_for_tests tests[NTESTS]
{
    {1, 2, 3, 1, 1},
    {}
};
*/
int     compare_doubles          (double k, double n);

void    solve_quadratic_equation (double a, double b, double c, double* x1, double* x2, int* nRoots);

void    print_root               (double x1, double x2, int nRoots);

int     get_coeff                (double* a, double* b, double* c);

void    solve_linear_equation    (double b, double c, int* nRoots, double* x1);
