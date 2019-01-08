#include <stdio.h>
#include <errno.h>

int append_line(char *word, char *history_file)
{
	int errnum = 0;
	FILE *fp = fopen(history_file, "a");

	if (fp == NULL) {
		errnum = errno;
		perror("Error opening the history file: ");
	} else {
		fprintf(fp, "%s\n", word);
		fclose(fp);
	}

	return errnum;
}


int add_to_history(char *word, char *history_file)
{
	int errnum = append_line(word, history_file);
	return errnum;
}
