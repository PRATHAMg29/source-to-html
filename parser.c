#include "html.h"
#include "parser.h"
#include "main.h"
#include "keywords.h"

void parse_source(FILE *src, FILE *dest, int line_number)
{
    char ch;
    char token[100];
    int index = 0;

    while((ch = fgetc(src)) != EOF)
    {
        if(ch == '"')   //string.
        {
            char str[100];
            int i = 0;
            str[i++] = ch;
            while((ch = fgetc(src)) != EOF)
            {
                str[i++] = ch;
                if(ch == '\\')
                {
                    ch = fgetc(src);
                    if(ch == EOF)
                    {
                        break;
                    }
                    str[i++] = ch;
                }
                else if(ch == '"')
                {
                    break;
                }
            }
            str[i] = '\0';
            write_string(dest, str);
            continue;
        }
        if(ch == '\'')  //character literals.
        {
            char chr[20];
            int c = 0;
            chr[c++] = ch;
            while((ch = fgetc(src)) != EOF)
            {
                chr[c++] = ch;
                if(ch == '\\')
                {
                    ch = fgetc(src);
                    if(ch == EOF)
                    {
                        break;
                    }
                    chr[c++] = ch;
                }
                else if(ch == '\'')
                {
                    break;
                }
            }
            chr[c] = '\0';
            write_character(dest, chr);
            continue;
        }
        if(ch == '/')   //comments.
        {
            char next = fgetc(src);
            if(next == '/')
            {
                char comment[100];
                int cm = 0;
                comment[cm++] = '/';
                comment[cm++] = '/';
                while((ch = fgetc(src)) != EOF && ch != '\n')
                {
                    comment[cm++] = ch;
                }
                comment[cm] = '\0';
                write_comment(dest, comment);
                if(ch == '\n')
                {
                    write_char(dest, '\n');
                }
                continue;
            }
            else if(next == '*')
            {
                char comment[500];
                int cm = 0;
                comment[cm++] = '/';
                comment[cm++] = '*';
                char prev = 0;
                while((ch = fgetc(src)) != EOF)
                {
                    comment[cm++] = ch;
                    if(prev == '*' && ch == '/')
                    {
                        break;
                    }
                    prev = ch;
                }
                comment[cm] = '\0';
                write_comment(dest, comment);
                continue;
            }
            else
            {
                write_char(dest, '/');
                if(next != EOF)
                {
                    ungetc(next, src);
                }
                continue;
            }
        }
        if(ch == '#')   //pre-processor directive.
        {
            char pre[50];
            int p = 0;
            pre[p++] = ch;
            while((ch = fgetc(src)) != EOF && ch != '\n')
            {
                pre[p++] = ch;
            }
            pre[p] = '\0';
            write_preprocessor(dest, pre);
            // if(ch == '\n')
            // {
            //     write_char(dest, '\n');
            // }
            continue;
        }
        if(isalnum(ch) || ch == '_' || ch == '.')
        {
            token[index++] = ch;
        }
        else
        {
            if(index != 0)
            {
                token[index] = '\0';

                if(is_keyword(token) == SUCCESS)
                {
                    write_keyword(dest,token);
                }
                else if(is_number(token) == SUCCESS)
                {
                    write_number(dest,token);
                }
                else
                {
                    write_identifier(dest,token);
                }

                index = 0;
            }
            write_char(dest, ch);
        }
    }
    if(index != 0)
    {
        token[index] = '\0';

        if(is_keyword(token) == SUCCESS)
        {
            write_keyword(dest, token);
        }
        else
        {
            write_identifier(dest, token);
        }
    }
}