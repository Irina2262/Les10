#include <stdio.h>
#include <string.h>
const int line_width = 1024;

void change_symbols(int size, char *line)
{
    int i = 0, j;
    char b;
    while (i < size)
    {
        while (line[i] == ' ') i++;
        j = i + 1;
        while (line[j] == ' ') j++;
        if (j >= size) break;
        b = line[i];
        line[i] = line[j];
        line[j] = b;
        i = j + 1;
    }
}
int main (void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
FILE *fp;

    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", line);
    fclose(fp);
    change_symbols(strlen(line), line);
    
    fp = fopen (output_fn, "W");
    fprintf(fp, "%s", line);
    fclose(fp);
    
	return 0;
}

