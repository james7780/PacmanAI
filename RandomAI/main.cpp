// RandomAI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RandomAI.h"
#include "malloc.h"

/// Read the game state board from disk
static char *readBoard(char *fileName)
{
	char *buffer = NULL;
	FILE *pfile = fopen(fileName, "rb");
	if (pfile)
		{
		// Our local buffer holds the missing 2 bytes at the end of the file, but we
		// only read what the file has
		buffer = (char *)malloc(BOARD_WIDTH * BOARD_HEIGHT);
		size_t bytesRead = fread(buffer, 1, BOARD_WIDTH * BOARD_HEIGHT - 2, pfile);
		fprintf(stdout, "Bytes read = %d\n", bytesRead);
		fclose(pfile);
		}

	return buffer;
}

/// Write the game state board to disk
static void writeBoard(char *fileName, char *buffer)
{
	FILE *pfile = fopen(fileName, "wb");
	if (pfile)
		{
		// Write out the buffer, minus the omitted CRLF on the end of the last line
		size_t bytesWritten = fwrite(buffer, 1, BOARD_WIDTH * BOARD_HEIGHT - 2, pfile);
		fprintf(stdout, "Bytes written = %d\n", bytesWritten);
		fclose(pfile);
		}
}

int main(int argc, char* argv[])
{
	fprintf(stdout, "Num args: %d", argc);
	fprintf(stdout, "\n");
	fprintf(stdout, argv[0]);
	fprintf(stdout, "\n");
	if (argc > 1)
		{
		fprintf(stdout, argv[1]);
		fprintf(stdout, "\n");

		char *fileName = argv[1];
		fprintf(stdout, "Reading state from %s\n", fileName);
		char *buffer = readBoard(fileName);
		if (buffer)
			{
			fprintf(stdout, "Processing board...\n");
			CRandomAI randomAI(buffer, 'B');
			randomAI.CalculateMove();
			randomAI.GetBoard(buffer);
			
			fprintf(stdout, "Writing results to %s\n", fileName);
			writeBoard(fileName, buffer);
			free(buffer);
			}
		else
			{
			fprintf(stdout, "Could not read board %s\n", fileName);
			}
		}

	fprintf(stdout, "Press ENTER to end");
	fgetc(stdin);

	
	return 0;
}

