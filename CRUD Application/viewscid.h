int check_valid_ssn(int class_id, char *SSN);

int findAssignment(int assignment_id, char *social)
{
  FILE *fp;
  struct grades data;
  fp = fopen("grades.db", "r+");
  int reVal = 0;
  
  while(fread(&data, sizeof(struct grades), 1, fp))
  {
    if(data.assignment_id == assignment_id && strncmp(social, data.ssn, 9) == 0)
    {
      reVal = data.point;
      fclose(fp);
      return reVal;
    }
  }
  fclose(fp);
  return 0;
}

void view_grade_student_ssn_cid(char *SSN, int class_id)
{
  if(strlen(SSN) != 9)
  {
    printf("Please enter social security number of 9 characters\n");
    return;
  }

  char social[9];
  memcpy(social, SSN, 9);
  
  if(check_valid_ssn(class_id, social))
  {
    int totalVal = 0;
    int counter = 0;
    FILE *fp;
    struct assignment data;
    fp = fopen("assignments.db", "r+");
 
    if(fp == NULL)
    {
      printf("\n Error: Cannot open assignment file");
      exit(1);
    }
  
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
      if(data.class_id == class_id)
      {
	totalVal = totalVal + findAssignment(data.assignment_id, social);
        counter++;
      }
    }
    printf("Average of this student is %d\n", totalVal/counter);
    

    fclose(fp);
  }
  else
  {
    printf("SSN not found in the database\n");
  }   
}
