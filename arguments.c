#include "main.h"

int check_arguments(int argc, char *argv[],Arguments *arg)
{
    if(argc > 1 && argc < 5)
    {
        char *p = strstr(argv[1],".");
        if(p == NULL || (strcmp(p,".c") != 0))
        {
            printf("Enter a source file name with '.c' extension.\n");
            return FAILURE;
        }
        else
        {
            strcpy(arg->input_file,argv[1]);
            if(argv[2] == NULL)
            {
                strcpy(arg->output_file,"output.html");
                arg->line_number = 0;
                return SUCCESS;
            }
        }

        if(argv[2] != NULL)
        {
            p = strstr(argv[2],".");
            if(p == NULL || (strcmp(p,".html") != 0))
            {
                printf("Enter a output file name with '.html' extension.\n");
                return FAILURE;
            }
            else
            {
                strcpy(arg->output_file,argv[2]);
                if(argv[3] == NULL)
                {
                    arg->line_number = 0;
                    return SUCCESS;
                }
            }
        }

        if(argv[3] != NULL)
        {
            p = strstr(argv[3],"-");
            if(p == NULL || (strcmp(p,"-l") != 0))
            {
                printf("Enter proper '-l' argument for line number.\n");
                return FAILURE;
            }
            else
            {
                arg->line_number = 1;
                return SUCCESS;
            }
        }   
    }
    return FAILURE;
}