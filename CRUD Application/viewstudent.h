void view_student_data_menu()
{
  FILE *fp;
  int i;
  struct student data;
  fp = fopen("students.db", "r");

  if(fp == NULL)
  {
    printf("\n Error: Cannot open file");
    exit(1);
  }
  printf("\n\nStudents in the database\n");
  while(fread(&data, sizeof(struct student), 1, fp))
  {
    printf("\nFirst name: %s, Last name = %s, SSN = ", data.fname, data.lname);
    for (i = 0; i < 9; i++)
    {
      printf("%c",data.ssn[i]);
    }
    printf("\n");
  }
  printf("\n\n");
}
