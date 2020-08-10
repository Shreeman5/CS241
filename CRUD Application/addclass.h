void add_class(char *title)
{
  char cname[30];

  memcpy(cname, title, 30);
  FILE *fp;
  FILE *nfp;
  struct classes data;

  null_terminate_name(cname, strlen(cname));

  fp = fopen("classes.db", "r");
  if(fp == NULL)
  {
    nfp = fopen("classes.db", "w");
    memcpy(data.title, cname, 30);
    data.id = 1;
    printf("%d\n", data.id);
    fwrite (&data, sizeof(struct classes), 1, nfp);
    printf("New file created and class added successfully\n\n");	
  }
  else
  {
    fseek(fp, -sizeof(struct classes), SEEK_END);
    fread(&data, sizeof(struct classes), 1, fp);
    memcpy(data.title, cname, 30);
    data.id = data.id + 1;
    printf("%d\n", data.id);
    nfp = fopen("classes.db", "a");
    fwrite (&data, sizeof(struct classes), 1, nfp);
    printf("Class added successfully\n\n");
  }
  fp = nfp;
  fclose(fp);
}

void get_class_data_menu()
{
  char title[31];
  printf("Enter Class Title: ");
  fgets(title, 31, stdin);

  if(title[0] == '\n')
  {
    printf("Title cannot be empty\n");
    return;
  }
  else if(strlen(title) <= 30)
  {
    delete_endline(title);
  }
  else
  {
    delete_endline(title);
    getchar();
  }

  add_class(title);
}
