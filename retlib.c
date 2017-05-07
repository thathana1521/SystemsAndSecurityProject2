/* retlib.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(FILE *badfile) {
	char buf[12];
	int r;
	
	/* The following statement has a buffer overflow problem */
	r=fread(buf, sizeof(char), 80, badfile);
	printf("\nRead %d bytes. buf is %s\n", r, buf);
	return 1;
}

int main(int argc, char **argv) {
	FILE *badfile;
	badfile = fopen("badfile", "r");
	bof(badfile);
	printf("Returned Properly\n");
	fclose(badfile);
	return 1;
}
