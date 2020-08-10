int check_valid_id(int class_id, int assignment_id)
{
  printf("Only opening assignments\n");
  FILE *fp;
  struct assignment data;
  fp = fopen("assignments.db", "r");

  if(fp == NULL)
  {
    printf("\n Assignment DB not found");
    exit(1);
  }

  while(fread(&data, sizeof(struct assignment), 1, fp))
  {
    if (data.class_id == class_id && data.assignment_id == assignment_id)
    {
      return 1;
    }
  }

  return 0;
}

void edit_assignment(int class_id, int assignment_id, char *title, int point)
{
  int point_val = 0;
  if(check_valid_class_id(class_id) && check_valid_id(class_id, assignment_id))
  {
    printf("Valid class Id and assignment id\n");
    
    if(strlen(title) < 1)
    {
      printf("Title should be atleast one character \n\n");
      return;
    }

    if (point == 662497)
    {
      point_val = 1;
    }

    if (!point_val)
    {
      if(point < 0 || point > 100)
      {
	printf("Point must be between 0 and 100 \n");
        return;
      }
    }

    char aname[30];
    memcpy(aname, title, 30);

    FILE *fp;
    struct assignment data;
    int counter = 0;
    int found = 0;


    null_terminate_name(aname, strlen(aname));
    fp = fopen("assignments.db", "r+");

    if(fp == NULL)
    {
      printf("\n Error: Cannot open file");
      exit(1);
    }


    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
      if(data.class_id == class_id && data.assignment_id == assignment_id)
      {
	found = 1;
        break;
      }
      counter++;
    }

    if(! found)
    {
      printf("Class ID and Assignment ID not found in database\n");
      fclose(fp);
      return;
    }
    else
    {
      fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
      fread(&data, sizeof(struct assignment), 1, fp);

      if (strcmp(title,"NULL") == 0 && point == 662497 )
      {
	printf("Nothing in the database changed\n\n");
	fclose(fp);
	return;
      }
      else if (strcmp(title,"NULL") == 0)
      {
	data.point = point;
	fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
        fwrite (&data, sizeof(struct assignment), 1, fp);
	printf("Points in the database changed\n\n");
      }
      else if (point == 662497)
      {
	memcpy(data.title, aname, 30);
	fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
        fwrite (&data, sizeof(struct assignment), 1, fp);
	printf("Title in the database changed\n\n");
      }
      else
      {
	data.point = point;
        memcpy(data.title, aname, 30);	
        fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
	fwrite (&data, sizeof(struct assignment), 1, fp);
        printf("Both title and points changed\n\n");
      }
      fclose(fp);
    }
  }
  else
  {
      printf("invalid\n");
      return;
  }
}

void edit_assignment_data_menu()
{
  char classID[10];
  int class_id;

  char assignmentID[10];
  int assignment_id;

  int point;
  char grade[10];

  char title[31];
  
  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);
  if(class_id == -1)
  {
    view_class_data_menu();
    edit_assignment_data_menu();
    return;
  }

  printf("Enter Assignment ID or (-1 for Assignment List): ");
  fgets(assignmentID, 10, stdin);
  assignment_id = atoi(assignmentID);

  while(assignment_id == -1)
  {
    view_assignment(class_id);
    printf("Enter Assignment ID or (-1 for Assignment List): ");
    fgets(assignmentID, 10, stdin);
    assignment_id = atoi(assignmentID);
  }

  printf("Enter Assignment Title: (or leave blank for no change)  ");
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

  printf("Enter New Point Value (1-100): ");
  fgets(grade, 10, stdin);
  if(grade[0] == '\n')
  {
    point = 662497;
  }
  else
  {
    point = atoi(grade);
  }

  //printf("Class_id = %d, Assignment_id = %d, title = %s, point = %d \n", class_id, assignment_id, title, point);
  edit_assignment(class_id, assignment_id, title, point);
}
