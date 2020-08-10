void clear_buffer() { while( getchar() != '\n' ) {} }

void delete_endline(char * input)
{
  int length = strlen(input);
  input[length - 1] = '\0';
}

void delete_endline_ssn(char * input)
{
  int length = strlen(input);
  input[length - 1] = '\0';
}

void null_terminate_name(char * input, int length)
{
  int i = 0;
  for ( i = length; i < 30; i++)
  {
    input[i] = '\0';
  }
}
