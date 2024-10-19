// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    BYT
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&b, sizeof(b), 1, input);
        fwrite(&b, sizeof(b), 1, output);
    }

    fseek(input, 44, SEEK_SET);
    fseek(output, 44, SEEK_SET);

    typedef int16_t buffer;
    buffer s;

    while (fread(&s, sizeof(s), 1, input) != 0)
    {
        s = s * factor;
        fwrite(&s, sizeof(s), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
