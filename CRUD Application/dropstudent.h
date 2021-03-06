int check_valid_class_id(int class_id);
int check_valid_ssn(int class_id, char *SSN);
void delete_grade_relationships(int assignment_id);

void delete_grade_from_existence(int class_id)
{
  FILE *fp;
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
      printf("dank memes\n");
      delete_grade_relationships(data.assignment_id);
    }
  }
  fclose(fp);
  return;
}

void drop_student(int class_id, char *SSN)
{
  if(strlen(SSN) != 9)
  {
    printf("Please enter social security number of 9 characters\n");
    return;
  }

  char social[9];
  memcpy(social, SSN, 9);
  
  if(check_valid_class_id(class_id) && check_valid_ssn(class_id, social))
  {
    FILE *fp;
    struct enrollment data;
    int found = 0;
    int counter = 0;
    int response = 0;
    int i;
    
    fp = fopen("enrollment.db", "r");
    if(fp == NULL)
    {
      printf("\n Error: Cannot open enrollment file");
      exit(1);
    }
    while(fread(&data, sizeof(struct enrollment), 1, fp))
    {
      if(data.id == class_id && (strncmp(data.ssn, social, 9) == 0))
      {
	printf("dank memes\n");
        found = 1;
	break;
      }
      counter++;
    }
    if(! found)
    {
      printf("not found in the database\n");
      fclose(fp);
      return;
    }
    else
    {
      found = 0;
      fseek(fp, counter*sizeof(struct enrollment), SEEK_SET);
      fread(&data, sizeof(struct enrollment), 1, fp);
      printf("Are you sure you want to delete ClassID = %d SSN = ", data.id);
      for (i = 0; i < 9; i++)
      {
	printf("%c",data.ssn[i]);
      }
      printf(" from the database? [Y/N]  ");   
      rewind(fp);
      response = getchar();
      getchar();
      if(response == 'Y')
      {
	FILE *fp_tmp;
        fp_tmp = fopen("tmp.db", "w");
	if(fp_tmp == NULL)
        {
	  printf("\n Error: Cannot open file");
          exit(1);
	}
	while (fread(&data, sizeof(struct enrollment), 1, fp))
	{
          if (data.id == class_id && (strncmp(data.ssn, social, 9) == 0))
	  {
	    printf("A record with requested name found and deleted.\n\n");
            found = 1;
	  }
	  else
          {
	    fwrite(&data, sizeof(struct enrollment), 1, fp_tmp);
	  }
	}
        delete_grade_from_existence(class_id);
	fclose(fp);
        fclose(fp_tmp);
	remove("enrollment");
        rename("tmp.db", "enrollment.db");
	return;
      }
      else
      {
	printf("dang son\n");
      }
      fclose(fp);
    }
  }
  else
  {
    printf("not here\n");
  }
} 

void dropping_student()
{
  char classID[10];
  int class_id;
  char SSN[12];

  printf("Enter Class ID or (-1 for Class List): ");
  fgets(classID, 10, stdin);
  class_id = atoi(classID);

  if(class_id == -1)
  {
    view_class_data_menu();
    dropping_student();
    return;
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
  printf("CID = %d, SSN = %s\n", class_id, SSN); 
  drop_student(class_id, SSN);
}
