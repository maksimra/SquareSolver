#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include <ctype.h> //swap обобщенный для того, чтобы менять ещё и размеры

enum error {NO_ERROR,
            ERROR_FOPEN,
            ERROR_FSEEK,
            ERROR_FTELL,
            ERROR_STAT,
            ERROR_STRCHR};

struct Lines {
    int lenght;
    char *ptr;
};

long int      memory_counter          (FILE *fp);
FILE*         open_file_and_fill_stat (const char *NAME, struct stat *statbuf);
void          f_read                  (size_t size, FILE *fp, char* buffer);
void          error_output            (void);
void          bubble_sort             (char** lines, size_t line_counter);
int           my_strcmp               (char *s1, char *s2);
void          swap                    (struct Lines* onegin, int i);
void          print_size              (size_t size);
size_t        line_processing         (size_t size, char* buffer_stdfread);
char**        ptr_to_lines            (size_t size, size_t line_counter, char* buffer_stdfread);
struct Lines* lines_to_struct         (size_t line_counter, char** lines);
void          printf_text             (size_t line_counter, char** lines);
