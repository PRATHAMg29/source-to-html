#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Buffer size */
#define MAX_TOKEN_SIZE     256

/* HTML Colors */
#define KEYWORD_COLOR      "blue"
#define STRING_COLOR       "brown"
#define COMMENT_COLOR      "green"
#define NUMBER_COLOR       "red"
#define PREPROC_COLOR      "purple"
#define CHAR_COLOR         "orange"

#define SUCCESS 1
#define FAILURE 0

/* Parser States */
typedef enum
{
    IDLE,
    WORD,
    NUMBER,
    STRING,
    CHARACTER,
    COMMENT,
    PREPROCESSOR
} ParserState;

/* Command line arguments */
typedef struct
{
    char input_file[100];
    char output_file[100];
    int line_number;
} Arguments;

int check_arguments(int argc, char *argv[],Arguments *arg);

#endif