#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*
* This is a circular buffer that allows enqueue or dequeue arbitrary
* amount of bytes. The buffer size is limited to BUF_SIZE.
*/

static char *GetErrorString(int x);

#define BUF_SIZE    4096

typedef struct {
   int write_index;
   int read_index;
   char *buf;
   int size;
} circular_buf_t;

circular_buf_t buf;

/*
* Enqueue (size) bytes from (client_buf) to the local buf
* memory of (client_buf) is allocated by the caller
*/
int enqueue(char *client_buf, int size)
{
   if (size > BUF_SIZE) {
       printf("%s", GetErrorString(3));
       return 3;
   }

   int part1 = buf.size - buf.write_index;
   memcpy(client_buf, buf.buf + buf.write_index, part1);

   if (part1 != size) {
       int part2 = size - part1;
       memcpy(client_buf+part1, buf.buf[0], part2);
   }

   return 0;
}

/*
* Dequeue (size) bytes from the local buf to (client_buf),
* (client_buf) is allocated by the caller. It is okay to assume
* (client_buf) is big enough to hold all the (size) bytes
*/
int dequeue(char *client_buf, int size)
{
   if (size < BUF_SIZE) {
       printf("%s", GetErrorString(2));
       return 2;
   }

   int copy_size = buf.write_index - buf.read_index + 1;
   memcpy(client_buf, buf.buf + buf.write_index, copy_size);

   return 0;
}

static char *GetErrorString(int x)
{
   char errorString[20];

   switch ( x )
   {
       case 0:
           errorString = "Success -- No error.";
           break;
       case 2:
           errorString = "Overflow!";
           break;
   }

   errorString[19] = 0;
   return errorString;
}


int main(int argc,char* argv[])
{
   // initialize buffer
   buf.buf = malloc(BUF_SIZE);
   buf.size = BUF_SIZE;

   // Perform enqueue() and dequeue();

   // All completed, return
   return 0;
}

//Feedback/Observations
//1. In enqueue function, bytes are enqueued to client_buf instead of 
//from client_buf(as mentioned in the comments)
//2. In dequeue function, only bytes are dequeued into client buf (destination)
//Actual dequeue operation involves removing bytes from source as well, here
//it's just copied to a destination.
//3. case 3 not defined in switch statement, but used in line 31 in 
//enqueue function.
//4. can't copy error message directly to a char array as in line 71 and 
//line 74. Use strcpy or strncpy instead.
//5. in function GetErrorString, returning local variable char pointer. 
//Can either make it global or static so that it won't be deallocated before
//copying.