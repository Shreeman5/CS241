int check_valid_class_id(int class_id);

void findAvgOfAssignment(int assignment_id)
{
  FILE *fp;
  FILE *nfp;
  struct grades data;
  int val = 0;
  int counter = 0;

  
 
  fp = fopen("grades.db", "r+");
  if (fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }
    
  
  while(fread(&data, sizeof(struct grades), 1, fp))
  {
    if(data.assignment_id != 0)
    {
      if(assignment_id == data.assignment_id)
      {
	val = val + data.point;
	counter++;
      }
    }
  }

  if(val == 0 && counter == 0)
  {
    return;
  }
  else
  {
    printf("The class average for Assignment %d is %d\n", assignment_id, val/counter);
  }
  fclose(fp);
}

void view_class_avg_grade(int class_id)
{
  if(check_valid_class_id(class_id))
  {
    FILE *fp;
    struct assignment data;

    fp = fopen("assignments.db", "r+");

    if(fp == NULL)
    {
      printf("\n Error: Cannot open file");
      exit(1);
    }
      
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
      if(class_id == data.class_id)
      {
	findAvgOfAssignment(data.assignment_id);
      }
    }
    fclose(fp);
  }
  else
  {
    printf("invalid class id\n");
    return;
  }
}

void view_class_avg_grade_data_menu()
{
  char classID[10];
  int class_id;

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    view_class_avg_grade_data_menu();
    return;
  }
  
  //  printf("Class ID: %d", class_id);
  view_class_avg_grade(class_id);
}
