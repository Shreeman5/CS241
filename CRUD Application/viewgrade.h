void view_grade(int class_id, int assignment_id)
{
  FILE *fp;
  struct assignment data;
  int classID = 0;
  int found = 0;
  char social[9];
  int i;

  fp = fopen("assignments.db", "r+");
  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }
  while(fread(&data, sizeof(struct assignment), 1, fp))
  {
    if(class_id == data.class_id && assignment_id == data.assignment_id)
    {
      found = 1;
      classID = data.class_id;
    }
  }
  
  if (! found)
  {
    printf("Class ID and assignment ID don't match or weren't found\n");
    fclose(fp);
    return;
  }
  else
  {
    FILE *nfp;
    struct grades data2;
    nfp = fopen("grades.db", "r");
    if(nfp == NULL)
    {
      printf("\n Error: Cannot open file");
      exit(1);
    }
    while(fread(&data2, sizeof(struct grades), 1, nfp))
    {
      if(assignment_id == data2.assignment_id)
      {
	printf("\nFor classID = %d & assignmentID = %d, Student ", classID, data2.assignment_id);
	memcpy(social, data2.ssn, 9);
	for (i = 0; social[i] != '\0'; i++)
	{
          printf("%c",social[i]);
	}
	printf(" scored %d", data2.point); 
	printf("\n");
      }
    }
    fp = nfp;
    fclose(fp);
  }
  return;  
}

void view_grade_data_menu()
{
  char classID[10];
  int class_id;
  char assignmentID[10];
  int assignment_id;

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    view_grade_data_menu();
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
  printf("CID: %d, AID: %d\n", class_id, assignment_id);
  view_grade(class_id, assignment_id);
}
