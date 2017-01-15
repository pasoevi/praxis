#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define  My_Full_Name "AAA!"


int main(void) 
{

    size_t buffersize = (size_t)(4*5.75);  //or (4 bytes * 5.75) = 23 bytes
    char buffer [buffersize]; char source_file[200]; char destination_file[200];


    ssize_t bytes_read, bytes_written;

    int fdSource, fdDestination;

    mode_t mode = S_IRUSR | S_IWUSR;

    printf("Welcome to File Copy by %s\n", My_Full_Name);

    printf("Enter the name of the source file: ");

    scanf("%s", source_file);

    printf("Enter the name of the destination file: ");

    scanf("%s", destination_file);
    printf("%d\n", buffersize);

    fdSource = open(source_file, O_RDONLY);

        if(fdSource<0)
        {   
            perror("Open failed!!");
            return 1;
        }

        else
        {

            bytes_read = read (fdSource, buffer, sizeof(buffer));

            fdDestination = open (destination_file,  O_CREAT | O_WRONLY | mode);

            if(fdDestination<0)
            {   
                    perror("Oups!! cannot create file again!!");

                    return 1;
            }
            else
            {
                bytes_written = write(fdDestination, buffer, sizeof(buffer));
                printf("current content of buffer: %s\n", buffer); //just to check
                printf("current value of buffer size = %zd  \n", buffersize);//just to check
                printf("File copy was successful, with %d byte copied\n", bytes_written ); //the output says only 4 bytes are copied

            }

        }

    return;



} 
