#ifndef HTML_H
#define HTML_H

#include "main.h"

void write_html_header(FILE *dest);
void write_html_footer(FILE *dest);

void write_keyword(FILE *dest, char *token);
void write_identifier(FILE *dest, char *token);
void write_number(FILE *dest, char *token);
void write_string(FILE *dest, char *token);
void write_character(FILE *dest, char *token);
void write_comment(FILE *dest, char *token);
void write_preprocessor(FILE *dest, char *token);
void write_char(FILE *dest, char ch);

#endif