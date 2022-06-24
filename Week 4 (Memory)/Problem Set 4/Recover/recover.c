#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Open the forensic image file
    FILE *forensicImage = fopen(argv[1], "r");

    // Initialize things
    BYTE buffer[512];
    char fileName[8];
    int fileNumber = 0;
    FILE *image = NULL;

    // While there are still bytes to read in the forensic image...
    while(fread(&buffer, sizeof(buffer), 1, forensicImage))
    {
        // If a new jpg is detected...
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If this is not the first jpg...
            if (fileNumber != 0)
            {
                // Close the previous jpg file
                fclose(image);
            }

            // Open a new jpg file
            sprintf(fileName, "%03i.jpg", fileNumber);
            image = fopen(fileName, "w");
            fileNumber++;
        }

        if (fileNumber != 0)
        {
            // Write from buffer to jpg file
            fwrite(&buffer, sizeof(buffer), 1, image);
        }
    }

    // Close files
    fclose(image);
    fclose(forensicImage);
}