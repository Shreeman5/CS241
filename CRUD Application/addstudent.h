void add_student(char * first, char *last, char *ssn)
{

  if(strlen(ssn) != 9)
  {
    printf("Social Security Should have 9 characters \n\n");
    return;
  }

  char fname[30];
  char lname[30];
  char social[9];

  memcpy(fname, first, 30);
  memcpy(lname, last, 30);
  memcpy(social, ssn, 9);

  FILE *fp;

  struct student data;

  null_terminate_name(fname, strlen(fname));
  null_terminate_name(lname, strlen(lname));
  memcpy(data.fname, fname, 30);
  memcpy(data.lname, lname, 30);
  memcpy(data.ssn, social, 9);

  fp = fopen("students.db", "a");
  if(fp == NULL)
  {
    printf("\n Error: Cannot Open File");
    exit(1);
  }

  fwrite (&data, sizeof(struct student), 1, fp);
  printf("Students successsfully added to database!\n");
  fclose(fp); 
}


void get_student_data_menu()
{
  char first[31];
  char last[31];
  char ssn[12];

  printf("Enter First Name: ");
  fgets(first, 31, stdin);
  if(first[0] == '\n')
  {
    printf("First Name Cannot be empty\n");
    return;
  }
  else if(strlen(first) <= 30)
  {
    delete_endline(first);
  }
  else
  {
    // printf("Name must be less than 30 chars\n");
    delete_endline(first);
    getchar();
  }

  printf("Enter Last Name: ");
  fgets(last, 31, stdin);
  if(last[0] == '\n')
  {
    printf("Last Name Cannot be empty\n");
    return;
  }
  else if(strlen(last) <= 30)
  {
    delete_endline(last);
  }
  else
  {
    delete_endline(last);
    getchar();
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

  add_student(first, last, ssn);
  
}
