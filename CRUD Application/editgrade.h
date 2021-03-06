int check_valid_class_id(int class_id);
int check_valid_id(int class_id, int assignment_id);
int check_valid_ssn(int class_id, char *SSN);

void edit_grade(int class_id, int assignment_id,  char *SSN, int point)
{
  int point_val = 0;
  if(strlen(SSN) != 9)
  {
    printf("Please enter social security number of 9 characters\n");
    return;
  }

  if(point == 662497)
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
  
  char social[9];
  memcpy(social, SSN, 9);
  

  if(check_valid_class_id(class_id) && check_valid_id(class_id, assignment_id) && check_valid_ssn(class_id, social))
  {
    FILE *fp;
    FILE *afp;
    struct assignment data;
    struct student data2;
    int found = 0;
    int found2 = 0;
    fp = fopen("assignments.db", "r+");
    afp = fopen("students.db", "r+");

    if(fp == NULL)
    {
      printf("\n Error: Cannot open assignment file");
      exit(1);
    }
    if(afp == NULL)
    {
      printf("\n Error: Cannot open student file");
      exit(1);
    }

    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
      if(data.class_id == class_id && data.assignment_id == assignment_id)
      {
	found = 1;
        break;
      }
    }
    printf("Found = %d\n", found);

    while(fread(&data2, sizeof(struct student), 1, afp))
    {
      if (strncmp(data2.ssn, social, 9) == 0)
      {
	found2 = 1;
        break;
      }
    }
    printf("Found2 = %d\n", found2);
    fp = afp;
    fclose(fp);

    if(found == 1 && found2 == 1)
    {
      printf("Valid\n");
      FILE *rfp;
      struct grades data3;
      int found3 = 0;
      int counter = 0;

      rfp = fopen("grades.db", "r+");
      if(rfp == NULL)
      {
	printf("\n Error: Cannot open file");
	exit(1);
      }
      else
      {
	while(fread(&data3, sizeof(struct grades), 1, rfp))
	{
	  if(data3.assignment_id == assignment_id && (strncmp(data3.ssn, social, 9) == 0))
	  {
	      found3 = 1;
	      break;
	  }
	  counter++;
	}

	if(! found3)
	{
	  printf("Class ID and Assignment ID and SSN not found in database\n");
	  fclose(rfp);
	  return;
	}
	else
	{
	  if(point != 662497)
	  {
	    data3.point = point;
	    printf("data3.point = %d\n", data3.point);
	    fseek(rfp, counter*sizeof(struct grades), SEEK_SET);
	    fwrite (&data3, sizeof(struct grades), 1, rfp);
	    printf("Points changed\n\n");
	    fclose(rfp);
	  }
	  else
	  {
	    printf("Nothing in the database changed\n\n");
	    fclose(rfp);
	    return;
	  }
	}
      }
    }
    else if(found == 1 && found2 == 0)
    {
      printf("Did not find SSN\n");
    }
    else if(found == 0 && found2 == 1)
    {
      printf("Did not find assignment and class\n");
    }
    else
    {
      printf("Did not find assignment and class and SSN\n");
    }
  }
  else
  {
    printf("Invalid\n");
  }  
}

void edit_grade_data_menu()
{
  char classID[10];
  int class_id;
  char assignmentID[10];
  int assignment_id;
  char SSN[12];
  int point;
  char grade[10];

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    get_grade_data_menu();
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
  

  printf("Enter SSN: ");
  fgets(SSN, 12, stdin);
  if(strlen(SSN) > 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else if(strlen(SSN) < 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else
  {
    delete_endline_ssn(SSN);
  }

  printf("Enter Point: (or leave blank for no change) ");
  fgets(grade, 10, stdin);
  if(grade[0] == '\n')
  {
    point = 662497;
  }
  else
  {
    point = atoi(grade);
  }

  // printf("Class_id = %d, Assignment_id  = %d, SSN = %s, point = %d \n", class_id, assignment_id, SSN, point);

  edit_grade(class_id, assignment_id,  SSN, point);
}

