#include "pipe_networking.h"


int main() {
  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );

    while(1){
      char input[BUFFER_SIZE] = {0};
      if (read(from_client, input, sizeof(input)) == 0){
        break;
      }
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
