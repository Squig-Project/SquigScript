#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

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
		
		/*
        char *load_pos = strstr(token, "load");
        if (load_pos != NULL) 
        {
			char *module_pos = load_pos + "load ";
			
			HMODULE dll_handle = LoadLibraryA(module_pos);
			if (dll_handle == NULL) 
			{
				return;
			}
			
			FARPROC func_ptr = GetProcAddress(dll_handle, load_pos + module_pos);
        }
		*/

        int *val_buffer = (int *)malloc(sizeof(int) * 1);
        *val_buffer = 0;

        char *val_pos = strstr(token, "val");
        if (val_buffer && val_pos != NULL) 
        {
            int value = atoi(val_pos + strlen("val "));

            memcpy(val_buffer, &value, sizeof(value));
        }

        char *incr_pos = strchr(token, '+');
        if (incr_pos != NULL) 
        {
            (*val_buffer)++;
        }

        char *decr_pos = strchr(token, '-');
        if (decr_pos != NULL) 
        {
            (*val_buffer)--;
        }

        fprintf(stdout, "%d", *val_buffer);

        free(val_buffer);
        token = strtok(NULL, "{}");
    }

    free(main_buffer);
}

int main(void) 
{
    parse_string("{val 9 }");
    return 0;
}
