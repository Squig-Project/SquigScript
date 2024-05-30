#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dlfcn.h>

void parse_string(const char *str) 
{
    char *main_buffer = (char *)malloc(strlen(str) + 1);
    if (main_buffer == NULL) 
    {
        return;
    }

    strncpy(main_buffer, str, strlen(str) + 1);

    char *token = strtok(main_buffer, "{}");
    while (token != NULL)
    {
        char *print_pos = strstr(token, "print");
        if (print_pos != NULL) 
        {
            fprintf(stdout, "%s\n", print_pos + strlen("print "));
        }

        char *load_pos = strstr(token, "load");
        if (load_pos != NULL) 
        {
            // later
        }

        int *val_buffer = (int *)malloc(sizeof(int));
        char *val_pos = strstr(token, "val");
        if (val_buffer && val_pos != NULL) 
        {
            int value = atoi(val_pos + strlen("val "));

            memcpy(val_buffer, &value, sizeof(value));
        }

        

        token = strtok(NULL, "{}");
    }

    free(main_buffer);
}

int main(void) 
{
    parse_string("{val 5}");
    return 0;
}
