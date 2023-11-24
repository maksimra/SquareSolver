#include "onegin.h"
#include "colors.h"

enum error {NO_ERROR,
            ERROR_FOPEN,
            ERROR_FSEEK,
            ERROR_FTELL,
            ERROR_STAT,
            ERROR_STRCHR,
            ERROR_CALLOC} Error;

/*long int memory_counter (FILE *fp)
{
    if (fp == NULL)
    {
        Error = ERROR_FOPEN;
        perror ("Ошибка открытия файла");
    }
    long current = -1;
    if ((current = ftell (fp)) == -1)
    {
        Error = ERROR_FTELL;
        perror ("Ошибка чтения исходной позиции");
    }
    if (fseek (fp, 0, SEEK_END) != 0)
    {
        Error = ERROR_FSEEK;
        perror ("Ошибка установки позиции");
    }
    long int size = 0;
    if ((size = ftell (fp)) == -1)
    {
        Error = ERROR_FTELL;
        perror ("Ошибка чтения размера файла");
    }
    if (fseek (fp, current, SEEK_SET) != 0)
    {
        Error = ERROR_FSEEK;
        perror ("Ошибка установки позиции в исходную");
    }
    return size;
}*/

void f_read (size_t size, FILE *fp, char* buffer)
{
    assert (fp != 0);

    buffer = (char*) calloc (size + 1, sizeof (char));

    if (buffer == NULL)
    {
        perror ("Ошибка в выделении динамической памяти");
    }
    int position = ftell (fp);
    if (fseek (fp, 0, SEEK_SET) != 0)
    {
        Error = ERROR_FSEEK;
        perror ("Ошибка установки позиции в начальную");
    }
    for (long i = 0; i < size && (buffer[i] = fgetc (fp)) != EOF; i++)
        continue;
    if (fseek (fp, position, SEEK_SET) != 0)
    {
        Error = ERROR_FSEEK;
        perror ("Ошибка установки позиции в исходную");
    }
}
// NEEDS FREE() AFTER USE!!!
FILE* open_file_and_fill_stat (const char *NAME, struct stat *statbuf)
{
    FILE *fp = fopen (NAME, "rb");
    if (stat (NAME, statbuf) == -1)
    {
        Error = ERROR_STAT;
        perror ("Ошибка функции stat");
    }
    return fp;
}
void error_output (void)
{
    switch (Error)
    {
        case ERROR_FOPEN:
            printf ("Ошибка открытия файла :(\n");
            break;
        case ERROR_FSEEK:
            printf ("Ошибка установки позиции в файле :(\n");
            break;
        case ERROR_FTELL:
            printf ("Ошибка чтения позиции в файле :(\n");
            break;
        case ERROR_STAT:
            printf ("Ошибка использования функции stat :(\n");
            break;
        default:
            printf ("Чтение размера файла прошло успешно!\n");
    }
}
void bubble_sort (struct Lines* onegin, size_t line_counter)
{
    for (int pass = 0; pass < line_counter - 1; pass++)
    {
        int nswap = 0;
        for (int i = 0; i < line_counter - pass - 1; i++)
        {
            if (my_strcmp (onegin[i].ptr, onegin[i + 1].ptr) > 0)
            {
                swap (onegin, i);
                nswap += 1;
            }
        }
        if (nswap == 0)
            break;
    }
}
void end_bubble_sort (struct Lines* onegin, size_t line_counter) // спросить более опытных собратьев

int my_strcmp (char *s1, char *s2)
{
    int pos = 0;
    for ( ; *(s1 + pos) != 0 && *(s2 + pos) != 0; pos++)
    {
        if (*(s1 + pos) != *(s2 + pos))
            break;
    }
    int pos1, pos2;
    pos1 = pos2 = pos;
    while (*(s1 + pos1) != 0 && *(s2 + pos2) != 0)
    {
        if (isalpha(*(s1 + pos1)) && isalpha (*(s2 + pos2)))
        {
            if (*(s1 + pos1) > *(s2 + pos2))
                return 1;
            else if (*(s1 + pos1) < *(s2 + pos2))
                return -1;
        }
        if (!isalpha(*(s1 + pos1)))// while, что на буквах
            pos1++;
        if (!isalpha(*(s2 + pos2))) //в цикле сидеть пока буквы или пробел
            pos2++;
    }
    return 0; // структуру для сортировки с конца, туда всё про строку
}

void swap (struct Lines* onegin, int i)
{
    char* temp = NULL;
    temp = onegin[i].ptr;
    onegin[i].ptr = onegin[i + 1].ptr;
    onegin[i + 1].ptr = temp;
    int temp_lenght = 0;
    temp_lenght = onegin[i].lenght;
    onegin[i].lenght = onegin[i + 1].lenght;
    onegin[i + 1].lenght = temp_lenght;
}

void print_size_and_numlines (size_t size, size_t num_lines)
{
    printf (PAINT_TEXT(YELLOW, "SIZE (from statbuf) = %zu\n NUMLINES = %zu"), size, num_lines);
}
size_t line_processing (size_t size, char* buffer_stdfread)
{
    size_t line_counter = 0;
    for (size_t k = 0 ; k < size; k++)
    {
        if (buffer_stdfread[k] == '\r')
        {
            line_counter++;
            buffer_stdfread[k] = '\0';
            k++;
            continue;
        }
        if (buffer_stdfread[k] == '\n')
        {
            line_counter++;
            buffer_stdfread[k] = '\0';
            continue;
        }
    }
    if (buffer_stdfread[size - 1] != '\n' && buffer_stdfread[size - 1] != '\r')
        line_counter++;
    return line_counter;
}

char** ptr_to_lines (size_t size, size_t line_counter, char* buffer_stdfread)
{
    char** lines = (char**) calloc (line_counter + 1, sizeof (char*));
    if (lines == NULL)
    {
        Error = ERROR_CALLOC;
        printf ("Ошибка выделения памяти под массив указателей!\n");
    }
    size_t a = 1;
    for (size_t k = 0; k < size + 1; k++)
    {
        if (buffer_stdfread[k] == '\0')
        {
            k += 2;
            lines[a] = buffer_stdfread + k;
            a++;
        }
    }
    return lines;
}

struct Lines* lines_to_struct (size_t line_counter, char** lines)
{
    struct Lines onegin[line_counter] = {};
    for (size_t i = 0; i < line_counter; i++)
    {
        onegin[i].lenght = lines[i + 1] - lines[i] - 2;
        onegin[i].ptr = lines[i];
    }
    return onegin;
}

void printf_text (size_t line_counter, char** lines)
{
    printf (PAINT_TEXT(YELLOW, "Сейчас будет распечатка текста!")"\n");
    for (int i = 0; i <= line_counter; i++)
        printf ("%s", lines[i]);
    return 0;
}
