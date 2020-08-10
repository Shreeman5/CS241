int check_valid_class_id(int class_id);

int check_valid_person(char *social)
{
  FILE *fp;
  struct student data;
  fp = fopen("students.db", "r");

  if(fp == NULL)
  {
    printf("\n Student DB not found\n\n");
    exit(1);
  }

  while(fread(&data, sizeof(struct student), 1, fp))
  {
    if(strncmp(data.ssn, social, 9) == 0)
    {
      return 1;
    }
  }
  printf("This student was not in the database\n");

  return 0;
  
}

void enroll_student(int class_id, char *SSN)
{
  if(strlen(SSN) != 9)
  {
    printf("Please enter social security number of 9 characters\n");
    return;
  }
  char social[9];
  memcpy(social, SSN, 9);

  if(check_valid_class_id(class_id) && check_valid_person(social))
  {
    FILE *fp;
    FILE *afp;
    struct classes data;
    struct student data2;
    int found = 0;
    int found2 = 0;

    fp = fopen("classes.db", "r+");
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

    while(fread(&data, sizeof(struct classes), 1, fp))
    {
      if(data.id == class_id)
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
      FILE *sfp;
      struct enrollment data3;

      rfp = fopen("enrollment.db", "r");
      if(rfp == NULL)
      {
	sfp = fopen("enrollment.db", "w");
        data3.id = class_id;
	printf("Class id: %d\n", data3.id);
	memcpy(data3.ssn, social, 9);
        fwrite (&data3, sizeof(struct enrollment), 1, sfp);
        printf("Enrolled successfully and new file created\n\n");
      }
      else
      {
	printf("sanko\n");
	fseek(rfp, -sizeof(struct enrollment), SEEK_END);
	fread(&data3, sizeof(struct enrollment), 1, rfp);
	data3.id = class_id;
	printf("Class id: %d\n", data3.id);
	sfp = fopen("enrollment.db", "a");
	memcpy(data3.ssn, social, 9);
	fwrite (&data3, sizeof(struct enrollment), 1, sfp);
	printf("Enrolled successfully\n\n");
      }
      rfp = sfp;
      fclose(rfp);
    }
    else if(found == 1 && found2 == 0)
    {
      printf("Did not find SSN\n");
    }
    else if(found == 0 && found2 == 1)
    {
      printf("Did not find class\n");
    }
    else
    {
      printf("Did not find class and SSN\n");
    }
  }
  else
  {
    printf("not here\n");
  }
}

void enrolling_student()
{
  char classID[10];
  int class_id = 0;
  char ssn[12];

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    enrolling_student();
    return;
  }

  printf("Enter SSN: ");
  fgets(ssn, 12, stdin);
  if(strlen(ssn) > 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else if(strlen(ssn) < 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else
  {
    delete_endline_ssn(ssn);
  }
  printf(" ID = %d, SSN = %s\n", class_id, ssn);
    
  enroll_student(class_id, ssn);
}
