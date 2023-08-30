#include "ded.h"

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoots = -1;
    int repeating_coeffs = 1;
    printf ("Поможем с решением квадратного уравнения:)\n");
    while (repeating_coeffs == 1)
    {
        get_coeff (&a, &b, &c);

        solve_quadratic_equation (a, b, c, &x1, &x2, &nRoots);

        print_root (x1, x2, nRoots);
        printf ("Введите 1 для продолжения\nили 0 - для окончания.\n");
        scanf ("%d", &repeating_coeffs);
    }
    printf ("До свидания!\n");

    return 0;
}