#include <stdio.h>
int main (void)
{
    int nteam;
    int k = 1;
    printf ("Введите количество команд:\n");
    scanf ("%d", &nteam);
    char res[nteam * (nteam - 1) / 2];
    for (int i = 0; i < nteam * (nteam - 1) / 2; k++)
    {
        printf ("Вводите результаты %d команды с другими командами по порядку:\n", k);
        for (int n = k + 1; n <= nteam; n++, i++)
        {
            scanf ("%d", res[i]);
        }
    }
    printf ("Сейчас вы увидете вывод турнирной таблицы треугольником.\n");
    int x = 1;
    int y = 0;
    for (int f = 0; f < nteam * (nteam - 1) / 2;)
    {
        for (x = y + 1; x < nteam; x++, f++)
        {
            printf ("%d", res[f]);
        }
        printf ("\n");
        y++;
    }
    return 0;
}