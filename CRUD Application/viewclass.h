void view_class_data_menu()
{
  char title[30];
  FILE *fp;
  int i;
  
  struct classes data;
  fp = fopen("classes.db", "r");

  if(fp == NULL)
  {
      printf("\n Error: Cannot open file");
      exit(1);
  }
  printf("\n\nClasses in the database:\n");
  while(fread(&data, sizeof(struct classes), 1, fp))
  {
    printf("Class ID: %d, Title: ", data.id);
    memcpy(title, data.title, 30);
    for (i = 0; title[i] != '\0'; i++)
    {
      printf("%c",title[i]);
    }
    printf("\n");
  }
  
  
  printf("\n\n");
  fclose(fp);
  return;
}
