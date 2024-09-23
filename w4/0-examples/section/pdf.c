#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // arguments security check
    if (argc < 2 || argc > 2)
    {
        printf("usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // collecting and storing the filename
    string filename = argv[1];

    // opening the file specified by the filename using "r"mode for reading
    FILE *f = fopen(filename, "r");

    // creation of var to store the file content from byte to byte
    // uint8_t = unsigned (only positive) integer of 8bits/1byte long
    // this is necessary because the normal int is 32bits/4bytes long
    uint8_t buffer[4];

    // reading from the file using the buffer, chunk size, number of chunks and the file pointer
    fread(buffer, 1, 4, f);

    // showing file content
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }
    fclose(f);
}
