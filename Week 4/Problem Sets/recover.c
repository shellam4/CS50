#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[]) {
    // check that user has entered 1 command line argument
    if (argc != 2) {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // open and read the file name given at argument 1 and create a pointer for that address of that content
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("File not working\n");
        return 1;
    }

    // Create buffer with size of 512 bytes
    unsigned char buffer[512];

    // Set boolean  of already found first jpeg to false
    bool found = false;

    // set filename length to 8
    char filename[8];
    FILE *img = NULL;

    // keep count of the number of images
    int counter = 0;

    while(fread(buffer, 512, 1, file) == 1) {

        // check if the is the start of a new image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

            // If first jpeg, start writing the very first file
            if (found == false) {

                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                if (img == NULL) {
                    return 3;
                }

                // Write from buffer into new file
                fwrite(&buffer, 512, 1, img);
                counter++;
                found = true;
            }

            // if found a jpeg that is not the first, then close file and open a new one to write to
            else if (found == true) {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                if (img == NULL) {
                    return 3;
                }

                // Write from buffer into new file
                fwrite(&buffer, 512, 1, img);
                counter++;
            }
        }

        // if no header, keep writing to file
        else if (found == true) {
                fwrite(&buffer, 512, 1, img);
        }

    }
    fclose(file);
    fclose(img);
}
