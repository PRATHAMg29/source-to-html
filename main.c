#include<stdio.h>
#include "main.h"
#include "keywords.h"
#include "html.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    Arguments arg;
    FILE *src;
    FILE *dest;
    if(argc < 2 || argc > 4)
    {
        printf("Invalid number of arguments. Type --help.\n");
        return FAILURE;
    }
    if(strcmp("--help",argv[1]) == 0)
    {

    }
    else if(check_arguments(argc,argv,&arg) == SUCCESS)
    {
        printf("VALIDATION SUCCESS.\n");
        // printf("%s\n%s\n%d\n",arg.input_file,arg.output_file,arg.line_number);
        src = fopen(arg.input_file,"r");
        if(src == NULL)
        {
            printf("Cannot open source file.\n");
            return FAILURE;
        }
        dest = fopen(arg.output_file,"w");
        if(dest == NULL)
        {
            printf("Cannot open destination file.\n");
            return FAILURE;
        }
        write_html_header(dest);
        parse_source(src, dest, arg.line_number);
        write_html_footer(dest);
        printf("Writing to %s file done.\n",arg.output_file);
    }
    else
    {
        return 0;
    }
}