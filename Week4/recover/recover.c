#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *source = fopen(argv[1], "r");

    if (source == NULL)
    {
        return 1;
    }

    int total_images = 0;
    BYTE buffer[BUFFER_SIZE];
    char *output_file = malloc(8 * sizeof(char));
    FILE *image = NULL;

    while (fread(buffer, BUFFER_SIZE, 1, source) == 1) // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    {
        // Check first 4 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >> 4) == 0x0e)
        {
            // only for first time
            if (total_images == 0)
            {
                sprintf(output_file, "%03i.jpg", total_images);
                image = fopen(output_file, "w");
                fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, image);
                total_images += 1;
            }
            else if (total_images > 0)
            {
                fclose(image);

                sprintf(output_file, "%03i.jpg", total_images);
                image = fopen(output_file, "w");
                fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, image);
                total_images += 1;
            }
        }
        else if (total_images > 0)
        {
            fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, image);
        }
    }

    free(output_file);
    fclose(source);
    fclose(image);
    return 0;
}
