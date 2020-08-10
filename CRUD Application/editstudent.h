void edit_student(char *first, char *last, char *social)
{
  if(strlen(first) < 1)
  {
    printf("First Name should be atleast one character \n\n");
    return;
  }

  if(strlen(last) < 1)
  {
    printf("Last Name should be atleast one character \n\n");
    return;
  }

  if(strlen(social) != 9)
  {
    printf("Social Security Should have 9 characters \n\n");
    return;
  }

  char fname[30];
  char lname[30];
  char ssn[9];

  memcpy(fname, first, 30);
  memcpy(lname, last, 30);
  memcpy(ssn, social, 9);
  
  FILE *fp;
  struct student data;
  int counter = 0;
  int found = 0;

  null_terminate_name(fname, strlen(fname));
  null_terminate_name(lname, strlen(lname));

  fp = fopen("students.db", "r+");
    
  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }
    

  while(fread(&data, sizeof(struct student), 1, fp))
  {
    if (strncmp(data.ssn,ssn,9) == 0)
    {
      found = 1;
      break;
    }
    counter++; 
  }

  if(! found)
  {
    printf("SSN not found in the database\n");
    fclose(fp);
    return;
  }
  else
  {
    fseek(fp, counter*sizeof(struct student), SEEK_SET);
    fread(&data, sizeof(struct student), 1, fp);
    if (strcmp(fname,"NULL") == 0 && strcmp(lname,"NULL") == 0 )
    {
      printf("Nothing in the database changed\n\n");
      fclose(fp);
      return;
    }
    else if (strcmp(fname,"NULL") == 0)
    {
      memcpy(data.lname, lname, 30);
      fseek(fp, counter*sizeof(struct student), SEEK_SET);
      fwrite (&data, sizeof(struct student), 1, fp); 
      printf("Last Name in the database changed\n\n");
    }
    else if (strcmp(lname,"NULL") == 0)
    {
      memcpy(data.fname, fname, 30);
      fseek(fp, counter*sizeof(struct student), SEEK_SET);
      fwrite (&data, sizeof(struct student), 1, fp);
      printf("First Name in the database changed\n\n");    
    }
    else
    {
      memcpy(data.lname, lname, 30);
      memcpy(data.fname, fname, 30);
      fseek(fp, counter*sizeof(struct student), SEEK_SET);
      fwrite (&data, sizeof(struct student), 1, fp);
      printf("Both first Name and last Name database changed\n\n");
    }
    fclose(fp);        
  }
}

void edit_student_data_menu()
{
  char social[12];
  char first[31];
  char last[31];
  
  printf("Enter SSN: ");
  fgets(social, 12, stdin);
  if(strlen(social) > 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else if(strlen(social) < 10)
  {
    printf("SSN should have 9 characters\n");
    return;
  }
  else
  {
    delete_endline_ssn(social);
  }
    
  printf("Enter new First Name (or leave blank for no change): ");
  fgets(first, 31, stdin);

  if(first[0] == '\n')
  {
    strcpy(first, "NULL");
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
    

  printf("Enter new Last Name (or leave blank for no change): ");
  fgets(last, 31, stdin);

  if(last[0] == '\n')
  {
    strcpy(last, "NULL");
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

  edit_student(first, last, social);
}
