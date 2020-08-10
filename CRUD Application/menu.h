void view_grades_menu()
{
  int choice = 0;

  printf("View Grades Menu\n");
  printf("1. View Class Average Grade \n");
  printf("2. View Student Average Grades \n");
  printf("3. View Class Assignment Average Grades\n");
  printf("4. View Class Assignment Grades\n");
  printf("5. Return to View Menu\n");
  printf("Please enter 1-5: ");

  scanf( "%d", &choice );
  clear_buffer();

  switch( choice )
  {
    case 1:
      printf( "\n\nViewing Class Average Grade\n\n" );
      view_class_avg_grade_data_menu();
      break;
    case 2:
      printf("\n\nViewing Student Average Grades\n\n");
      view_student_avg_grade_data_menu();
      break;
    case 3:
      printf("\n\nView Class Assignment Average Grades\n\n");
      view_class_avg_grade_data_menu();
      break;
    case 4:
      printf("\n\nView Class Assignment Grades \n\n");
      view_grade_data_menu();
      break;
    case 5:
      return;
    default:
      printf("\n\nPlease type a number from 1-5\n\n");
      break;
  }
  view_grades_menu();
}

void view_data_menu()
{
  int choice = 0;
    
  printf("View Data Menu\n");
  printf("1. View Student \n");
  printf("2. View Classes \n");
  printf("3. View Assignment\n");
  printf("4. View Grade\n");
  printf("5. View Enrollment\n");
  printf("6. Return to Main Menu\n");
  printf("Please enter 1-6: ");

  scanf( "%d", &choice );    
  clear_buffer();
    
  switch( choice )
  {
    case 1:
      printf("\n\nViewing Students \n\n");
      break;
    case 2:
      printf("\n\nViewing Class \n\n");
      view_class_data_menu();
      break;
    case 3:
      printf("\n\nViewing Assignments\n\n");
      view_assignment_data_menu();
      break;
    case 4:
      printf("\n\nViewing Grade \n\n");
      view_grade_data_menu();
      view_grades_menu();
      break;
    case 5:
      printf("\n\nViweing Student Enrollement\n\n");
      view_enrollment_data_menu();
      break;
    case 6:
      return;
    default:
      printf("\n\nPlease type a number from 1-6\n\n");
      break;
  }
  view_data_menu();
}

void delete_menu()
{
  int choice = 0;

  printf("Delete Data Menu\n");
  printf("1. Delete Student \n");
  printf("2. Delete Class \n");
  printf("3. Delete Assignment\n");
  printf("4. Delete Grade\n");
  printf("5. Drop Student\n");
  printf("6. Return to Main Menu\n");
  printf("Please enter 1-6: ");
    
  scanf( "%d", &choice );
  clear_buffer();

  switch( choice )
  {
    case 1:
      printf("\n\nDeleting Student \n\n");
      delete_student_data_menu();
      break;
    case 2:
      printf("\n\nDeleting Class \n\n");
      delete_class_data_menu();
      break;
    case 3:
      printf("\n\nDeleting Assignments\n\n");
      delete_assignment_data_menu();
      break;
    case 4:
      printf("\n\nDeleting Grade \n\n");
      delete_grade_data_menu();
      break;
    case 5:
      printf("\n\nDropping Student \n\n");
      dropping_student();
      break;
    case 6:
      return;
    default:
      printf("\nPlease type a number from 1-6\n\n");
      break;
  }
  delete_menu();
}

void edit_menu()
{
  int choice = 0;
  printf("Edit Data Menu\n");
  printf("1. Edit Student \n");
  printf("2. Edit Class \n");
  printf("3. Edit Assignment\n");
  printf("4. Edit Grade\n");
  printf("5. Return to Main Menu\n");
  printf("Please enter 1-5: ");

  scanf( "%d", &choice );
  clear_buffer();

  switch( choice )
  {
    case 1:
      printf("\n\nEditing Student\n\n");
      edit_student_data_menu();
      break;
    case 2:
      printf("\n\nEditing Class \n\n");
      edit_class_data_menu();
      break;
    case 3:
      printf("\n\nEditing Assignments\n\n");
      edit_assignment_data_menu();
      break;
    case 4:
      printf("\n\nEditing Grade \n\n");
      edit_grade_data_menu();
      break;
    case 5:
      return;
    default:
      printf("\nPlease type a number from 1-5\n\n");
      break;
  }
  edit_menu();
}

void add_data_menu()
{
  int choice;
  printf( "Add Data Menu\n" );
  printf( "1. Add Student\n" );
  printf( "2. Add Class\n" );
  printf( "3. Add Assignment\n" );
  printf( "4. Add Grade\n" );
  printf( "5. Enroll Student\n" );
  printf( "6. Return to Main Menu\n" );
  printf( "Please enter 1-6: " );

  scanf( "%d", &choice );
  clear_buffer();
    
  switch( choice )
  {
    case 1:
      printf( "\nAdd Student to Database\n\n" );
      get_student_data_menu();
      break;
    case 2:
      printf( "\nAdding Class\n\n" );
      get_class_data_menu();
      break;
    case 3:
      printf( "\nAdding Assignment\n\n" );
      get_assignment_data_menu();
      break;
    case 4:
      printf( "\nAdding Grade\n\n" );
      get_grade_data_menu();
      break;
    case 5:
      printf( "\nEnrolling Student\n\n" );
      enrolling_student();
      break;
    case 6:
      return;
    default:
      printf( "\nPlease type a number from 1-6\n\n" );
      break;
  }
  add_data_menu();
}

void main_menu()
{
  int choice;
  printf( "Main Menu\n" );
  printf( "1. Add Data\n" );
  printf( "2. Edit Data\n" );
  printf( "3. Delete Data\n" );
  printf( "4. View Data\n" );
  printf( "5. Use Custom Commands\n" );
  printf( "6. Exit\n" );
  printf( "Please enter 1-6: " );

  scanf( "%d", &choice );
  clear_buffer();

  switch( choice )
  {
    case 1:
      add_data_menu();
      break;
    case 2:
      edit_menu();
      break;
    case 3:
      delete_menu();
      break;
    case 4:
      view_data_menu();
      break;
    case 5:
      printf( "\nWe're using Custom Command\n\n" );
      custom_command();
      break;
    case 6:
      exit(1);
    default:
      printf( "\nPlease type a number from 1-6\n\n" );
      break;
  }
  main_menu();
}
