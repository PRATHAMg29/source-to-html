#include "keywords.h"

const char *keyword[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile"
    ,"while",NULL};

int is_keyword(char *word)
{
    for(int i=0; keyword[i] != NULL;i++)
    {
        if(strcmp(word,keyword[i]) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}

int is_number(char *token)
{
    int dot_count = 0;
    for(int i=0;token[i];i++)
    {
        if(token[i] == '.')
        {
            dot_count++;
        }
        else if((!isdigit(token[i])) || dot_count>1)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}