int check_valid_class_id(int class_id);

void findAvg(int assignment_id)
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


void view_grade_aid_cid(int class_id, int assignment_id)
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
	findAvg(assignment_id);
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
  
