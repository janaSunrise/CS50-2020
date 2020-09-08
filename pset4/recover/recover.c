#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    // is the m card valid? and can be opened?
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    //create variables that we're gonna use + alloc mem for files
    FILE *img;
    char filename[7];
    unsigned char *file_mem = malloc(512);
    int ctr = 0;

    while (fread(file_mem, 512, 1, file))
    {
        // is the jpg file found
        if (file_mem[0] == 0xff && file_mem[1] == 0xd8 && file_mem[2] == 0xff && (file_mem[3] & 0xf0) == 0xe0)
        {
            // close previous jpg file if exists in the dir
            if (ctr > 0)
            {
                fclose(img);
            }

            // create filename
            sprintf(filename, "%03d.jpg", ctr);
            img = fopen(filename, "w");

            // check if jpg file is successfully created
            if (img == NULL)
            {
                fclose(file);
                free(file_mem);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            ctr++;
        }

        //if any jpg file exists writes on the file currently opened
        if (ctr > 0)
        {
            fwrite(file_mem, 512, 1, img);
        }
    }

}
