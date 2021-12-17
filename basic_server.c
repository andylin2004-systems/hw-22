#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  while(1){
    from_client = server_setup();
    if (fork() == 0)
    {
      to_client = server_connect(from_client);
      
      while(1){
        char input[BUFFER_SIZE] = {0};
        read(from_client, input, sizeof(input));
        int i;
        for (i = 0; i < BUFFER_SIZE && input[i]; i++)
        {
          input[i] += 1;
          if (input[i] == 'a' || input[i] == 'A')
          {
            input[i] = '4';
          }
          else if (input[i] == 'e' || input[i] == 'E')
          {
            input[i] = '3';
          }
          else if (input[i] == 'I' || input[i] == 'i')
          {
            input[i] = '1';
          }
        }
        write(to_client, input, sizeof(input));
      }
    }
  }
}
