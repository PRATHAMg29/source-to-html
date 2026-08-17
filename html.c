#include "html.h"

void write_html_header(FILE *dest)
{
    fprintf(dest,"<html>\n");
    fprintf(dest,"<head>\n");
    fprintf(dest,"<title>SOURCE TO HTML</title>\n");
    fprintf(dest,"</head>\n");
    fprintf(dest,"<body>\n");
    fprintf(dest,"<pre>\n");
}

void write_html_footer(FILE *dest)
{
    fprintf(dest,"</pre>\n");
    fprintf(dest,"</body>\n");
    fprintf(dest,"</html>\n");
}

void write_keyword(FILE *dest, char *token)
{
    fprintf(dest,"<font color=\"%s\">%s</font>",KEYWORD_COLOR,token);
}

void write_identifier(FILE *dest, char *token)
{
    fprintf(dest, "%s", token);
}

void write_number(FILE *dest, char *token)
{
    fprintf(dest,"<font color=\"%s\">%s</font>",NUMBER_COLOR,token);
}

void write_string(FILE *dest, char *token)
{
    fprintf(dest,"<font color=\"%s\">%s</font>",STRING_COLOR,token);
}

void write_character(FILE *dest, char *token)
{
    fprintf(dest,"<font color=\"%s\">%s</font>",CHAR_COLOR,token);
}

void write_comment(FILE *dest, char *token)
{
    fprintf(dest,"<font color=\"%s\">%s</font>",COMMENT_COLOR,token);
}

void write_preprocessor(FILE *dest, char *token)
{
    // fprintf(dest, "<font color=\"%s\">%s</font>", PREPROC_COLOR,token);
    fprintf(dest, "<font color=\"%s\">", PREPROC_COLOR);
    for(int i = 0; token[i] != '\0'; i++)
    {
        write_char(dest, token[i]);
    }
    fprintf(dest, "</font>");
}

void write_char(FILE *dest, char ch)
{
    if (ch == '<')
    {
        fprintf(dest, "&lt;");
    }
    else if (ch == '>')
    {
        fprintf(dest, "&gt;");
    }
    else if (ch == '&')
    {
        fprintf(dest, "&amp;");
    }
    else
    {
        fputc(ch, dest);
    }
}