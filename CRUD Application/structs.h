struct student
{
    char fname[30];
    char lname[30];
    char ssn[9];
};

struct classes
{
    int id;
    char title[30];
};

struct enrollment
{
    int id;
    char ssn[9];
};

struct assignment
{
    int assignment_id;
    char title[30];
    int point;
    int class_id;
};

struct grades
{
  int assignment_id;
  char ssn[9];
  int point;
};
