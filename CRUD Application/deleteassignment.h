void delete_grade_relationships(int assignment_id)
{
  FILE *fp;

  struct grades data;
  int counter = 0;
  int found = 0;
  int response;
  fp = fopen("grades.db", "r");

  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    return;
  }
  while(fread(&data, sizeof(struct grades), 1, fp))
  {
    if (data.assignment_id == assignment_id)
    {
      found = 1;
      break;
    }
    counter++;
  }


  if(! found)
  {
    printf("No relationship with grade found\n");
    fclose(fp);
    return;
  }
  else
  {
    found = 0;
    fseek(fp, counter*sizeof(struct grades), SEEK_SET);
    fread(&data, sizeof(struct grades), 1, fp);
    rewind(fp);
    FILE *fp_tmp;
    fp_tmp = fopen("tmp2.db", "w");
    if(fp_tmp == NULL)
    {
      printf("\n Error: Cannot open file");
      exit(1);
    }
    while (fread(&data, sizeof(struct grades), 1, fp))
    {
      if (data.assignment_id == assignment_id)
      {
	found = 1;
      }
      else
      {
	fwrite(&data, sizeof(struct grades), 1, fp_tmp);
      }
    }
    
    if(found)
    {
      printf("\n Relationship with grades found and deleted\n\n");
    }

    fp = fp_tmp;
    fclose(fp);
    remove("grades.db");
    rename("tmp2.db", "grades.db");
  }
}


void delete_assignment(int class_id, int assignment_id)
{
  int point_val = 0;
  if(check_valid_class_id(class_id) && check_valid_id(class_id, assignment_id))
  {
    FILE *fp;
    struct assignment data;
    int found = 0;
    int counter = 0;
    int response = 0;
    fp = fopen("assignments.db", "r");

    if(fp == NULL)
    {
      printf("\n Error: Cannot open file");
      exit(1);
    }
    while(fread(&data, sizeof(struct assignment), 1, fp))
    {
      if(data.class_id == class_id && data.assignment_id == assignment_id)
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
      fseek(fp, counter*sizeof(struct assignment), SEEK_SET);
      fread(&data, sizeof(struct assignment), 1, fp);
      printf("Are you sure you want to delete Points = %d , Title = %s, ClassID = %d, AssignmentID = %d from the database [Y/N]: ", data.point, data.title, data.class_id, data.assignment_id);
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
        while (fread(&data, sizeof(struct assignment), 1, fp))
	{
	  if (data.class_id == class_id && data.assignment_id == assignment_id)
          {
      	    delete_grade_relationships(assignment_id);
            printf("A record with requested name found and deleted.\n\n");
	    found = 1;
	  }
	  else
      	  {
      	    fwrite(&data, sizeof(struct assignment), 1, fp_tmp);
      	  }
	}
	fp = fp_tmp;
	fclose(fp);
	  
	remove("assignments.db");
	rename("tmp.db", "assignments.db");
	return;
      }
      else
      {
	printf("ngannou\n");
      }
      fclose(fp);
    }
  }
  else
  {
    printf("Invalid\n");
  }
}

void delete_assignment_data_menu()
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
    delete_assignment_data_menu();
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

  printf("CID = %d, AID = %d", class_id, assignment_id);
  delete_assignment(class_id, assignment_id);
}
