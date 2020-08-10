void view_assignment(int class_id)
{
  char title[30];
  FILE *fp;
  int i;
  int found = 0;

  struct assignment data;
  fp = fopen("assignments.db", "r");

  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }
  
  while(fread(&data, sizeof(struct assignment), 1, fp))
  {
    if(data.class_id == class_id)
    {
      found = 1;
      printf("Class ID: %d, assignment ID: %d, Points: %d, Title: ", data.class_id, data.assignment_id, data.point);
      memcpy(title, data.title, 30);
      
      for (i = 0; title[i] != '\0'; i++)
      {
	printf("%c",title[i]);
      }
      printf("\n");
    }
  }

  if(!found)
  {
    printf("This class is not in the database\n");
  }
  
  printf("\n\n");
  fclose(fp);
  return;
}

void view_assignment_data_menu()
{
  char classID[10];
  int class_id;

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    view_assignment_data_menu();
    return;
  }
  
  view_assignment(class_id);
}
