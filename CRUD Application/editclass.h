void edit_class(int class_id, char * title)
{
  char cname[30];
  memcpy(cname, title, 30);
  
  FILE *fp;
  struct classes data;
  int counter = 0;
  int found = 0;

  null_terminate_name(cname, strlen(cname));
  fp = fopen("classes.db", "r+");

  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }

  while(fread(&data, sizeof(struct classes), 1, fp))
  {
    if(data.id == class_id)
    {
      found = 1;
      break;
    }
    counter++;
  }

  if(! found)
  {
    printf("Class Id not found in the database to edit\n");
    fclose(fp);
    return;
  }
  else
  {
    if(strcmp(cname,"NULL") == 0)
    {
      printf("Nothing in the database changed\n\n");
      fclose(fp);
      return;
    }
    fseek(fp, counter*sizeof(struct classes), SEEK_SET);
    memcpy(data.title, cname, 30);
    fwrite (&data, sizeof(struct classes), 1, fp);
    printf("Class Title in the database changed\n\n");
    fclose(fp);
  }
}

void edit_class_data_menu()
{
  char classID[10];
  int class_id;
  char title[31];
  
  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    edit_class_data_menu();  
    return;
  }
  
  printf("Enter Class Title: (or leave blank for no change) ");
  fgets(title, 31, stdin);

  if(title[0] == '\n')
  {
    strcpy(title, "NULL");
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

  edit_class(class_id, title);
}
