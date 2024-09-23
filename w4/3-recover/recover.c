#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// data block definition
#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // app usage and parameter validaton
    if (argc != 2)
    {
        printf("Usage: %s filename.raw\n", argv[0]);
        return 1;
    }

    if (argv[1] == NULL)
    {
        printf("Error, could not read the file %s\n", argv[1]);
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    // validation
    if (card == NULL)
        return 1;

    // Create a buffer for a block of data
    uint8_t buffer[BLOCKSIZE];

    // file, block counters
    int file_number = 0;
    int block = 1;

    // image pointer, global to be acessible in all call stacks, allowing closing when needed
    FILE *img;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCKSIZE, card) == BLOCKSIZE)
    {
        // filename var declaration, without malloc
        char filename[8];

        // create the filename and store it into the malloc with custom format
        sprintf(filename, "%03i.jpg", file_number);

        // checking for file patterns
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // first jpeg in jpegchaing check
            if (file_number == 0)
            {
                // first time opening the img pointer for writing
                img = fopen(filename, "w");
                // writing the first jpeg
                fwrite(buffer, BLOCKSIZE, 1, img);
                // increasing the file count
                file_number++;
            }
            else
            {
                // closing the previous file
                fclose(img);
                // opening a new file
                img = fopen(filename, "w");
                // writing into the new file
                fwrite(buffer, BLOCKSIZE, 1, img);
                // increasing the file count
                file_number++;
            }
        }
        else if (file_number != 0)
        {
            // continue writing into the currently open file
            fwrite(buffer, BLOCKSIZE, 1, img);
        }

        block++;
    }

    // closing the card and img files
    fclose(card);
    fclose(img);
    return 0;
}
