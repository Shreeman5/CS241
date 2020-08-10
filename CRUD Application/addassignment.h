int check_valid_class_id(int id)
{
  FILE *fp;
  struct classes data;
  fp = fopen("classes.db", "r");

  if(fp == NULL)
  {
    printf("\n Class DB not found");
    exit(1);
  }

  while(fread(&data, sizeof(struct classes), 1, fp))
  {
    if (data.id == id)
    {
      return 1;
    }
  }

  return 0;
}

void add_assignment(int class_id, char * title, int point)
{
  if(! check_valid_class_id(class_id))
  {
    printf("Not a valid class Id\n");
    return;
  }

  if(point < 0 || point > 100)
  {
    printf("Point must be between 0 and 100 \n");
    return;
  }

  char aname[30];
  memcpy(aname, title, 30);
  
  FILE *fp;
  FILE *nfp;
  struct assignment data;

  null_terminate_name(aname, strlen(aname));

  fp = fopen("assignments.db", "r");
  if(fp == NULL)
  {
    nfp = fopen("assignments.db", "w");
    data.assignment_id = 1;
    memcpy(data.title, aname, 30);
    data.class_id = class_id;
    data.point = point;
    printf("Class ID = %d\n", data.class_id);
    printf("Assignment ID = %d\n", data.assignment_id);
    fwrite (&data, sizeof(struct assignment), 1, nfp);
    printf("Assignment added successfully\n\n");
  }
  else
  {
    fseek(fp, -sizeof(struct assignment), SEEK_END);
    fread(&data, sizeof(struct assignment), 1, fp);
    data.assignment_id = data.assignment_id + 1;
    nfp = fopen("assignments.db", "a");
    memcpy(data.title, aname, 30);
    data.class_id = class_id;
    printf("Class ID = %d\n", data.class_id);
    printf("Assignment ID = %d\n", data.assignment_id);
    data.point = point;
    fwrite (&data, sizeof(struct assignment), 1, nfp);
    printf("Assignment added successfully\n\n");
  }
  fp = nfp;
  fclose(fp);

}

void get_assignment_data_menu()
{
  char classID[10];
  int class_id;
  char points[10];
  int point;
  char title[31];

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    get_assignment_data_menu();
    return;
  }

  printf("Enter Assignment Title: ");
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

  printf("Enter Point Value (1-100): ");
  fgets(points, 10, stdin);
  point = atoi(points);
  
  //printf("%lu\n", strlen(title));
  //  printf("Class_id = %d, title = %s, point = %d \n", class_id, title, point);

  add_assignment(class_id, title, point);
}
