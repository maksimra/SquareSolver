#include "onegin.h"
#include "colors.h"

int main (const int argc, const char** argv)
{
    enum error Error = NO_ERROR;
    const char *NAME = argv[1];
    struct stat statbuf = {};

    FILE *fp = open_file_and_fill_stat (NAME, &statbuf);
    char *buffer_stdfread = NULL;
    f_read (statbuf.size, fp, buffer_stdfread);

    size_t line_counter = line_processing (statbuf.size, buffer_stdfread);
    print_size_and_numlines (statbuf.size, line_counter);
    char** lines = ptr_to_lines (statbuf.size, line_counter, buffer_stdfread);
    struct Lines* onegin = lines_to_struct (line_counter, lines);
    error_output ();
    printf_text (line_counter, lines);
    bubble_sort (onegin, line_counter);
    printf_text (line_counter, lines);
    /*printf ("Вывод структуры строк:\n");
    for (size_t i = 0; i < line_counter; i++)
    {
        printf ("onegin[%d].lenght = %d\n", i, onegin[i].lenght);
    }
    printf ("\n\n>>>>>Сейчас будет печать по указателям\n\n");
    for (size_t k = 0; k < line_counter - 1; k++)
        printf ("%s\n", lines[k]);
    printf ("\n\n>>>>>Сейчас будет отсортированная печать\n\n");
    for (size_t k = 0; k < line_counter - 1; k++)
    printf ("%s\n", lines[k]);*/
    return 0;
}
