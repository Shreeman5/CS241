void main_menu();

void custom_command()
{
  char c;
  char *in = malloc(1000);
  int i;
  int index = 0;
  int num_args = 1;
  int curr_arg = 0;
  int inc = 0;
  int length = 0;

  printf( ">>" );

  while( ( c = getchar() ) != '\n' )
  {
    if ( c == ' ')
    {
      num_args++;
    }
    in[index] = c;
    index++;
  }
  printf("numargs : %d\n", num_args);
  printf("In: %s\n", in);
  
  

  length = index;
  index = 0;
  char **strs = malloc( sizeof( char * ) * num_args );
  
  while(index < length + 1)
  {
    if(in[index] == ' ' || in[index] == '\0' )
    {
      strs[curr_arg] = malloc( index - inc + 1 );
      for ( i = inc; i < index; i++ )
      {
	strs[curr_arg][i - inc] = in[i];
      }
      strs[curr_arg][i - inc] = '\0';
      inc = index + 1;
      curr_arg++;  
    }
    index++;
  }

  int j= 0;

  /*for( i = 0; i < num_args; i++ )
  {
    for(j = 0; j < strlen(strs[i]); j++)
    {
      printf("%c - %d\n", strs[i][j], strs[i][j]);
    }
    }*/
  //  return;

  if(num_args == 1 && (strcmp( strs[0], "exit" ) == 0  ||  strcmp(strs[0], "quit") == 0) )
  {
    printf("Im here\n");
    in = NULL;
    strs = NULL;
    free(in);
    free(strs);
    return;
  }
  else if(strcmp( strs[0], "use_menus" ) == 0)
  {
    printf("Im here\n");
    in = NULL;
    strs = NULL;
    free(in);
    free(strs);
    main_menu();    
  }
  else if(strcmp( strs[0], "add" ) == 0 && num_args > 1 && num_args <= 6 )
  {
    if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
    {
      add_grade( atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
    }
    else if(strcmp( strs[1], "student") == 0 && num_args == 5 )
    {
      add_student(strs[2], strs[3], strs[4]);
    }
    else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
    {
      add_class(strs[2]);
    }
    else if(strcmp( strs[1], "assignment") == 0 && num_args == 5 )
    {
      add_assignment(atoi(strs[2]), strs[3], atoi(strs[4]));
    }
    else
    {
      printf("Please type a valid add command\n");
    }
  }
  
  else if (strcmp( strs[0], "enroll" ) == 0 && num_args > 1 && num_args <= 3)
  {
    if(num_args == 3)
    {
      enroll_student(atoi(strs[1]), strs[2]);
    }
    else
    {
      printf("Please enter a valid enroll command \n");
    }
  }

  else if ( strcmp( strs[0], "edit" ) == 0 && num_args > 1 && num_args <= 6)
  {
    if(strcmp( strs[1], "student") == 0 && num_args == 5 )
    {
      edit_student(strs[3], strs[4], strs[2]);
    }
    else if(strcmp( strs[1], "class") == 0 && num_args == 4 )
    {
      edit_class(atoi(strs[2]), strs[3]);
    }
    else if(strcmp( strs[1], "assignment") == 0 && num_args == 6 )
    {
      edit_assignment(atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
    }
    else if(strcmp( strs[1], "grade") == 0 && num_args == 6 )
    {
      printf("Strs[0]: %s\n", strs[0]);
      printf("Strs[1]: %s\n", strs[1]);
      printf("Strs[2]: %s\n", strs[2]);
      printf("Strs[3]: %s\n", strs[3]);
      printf("Strs[4]: %s\n", strs[4]);
      printf("Strs[5]: %s\n", strs[5]);
      
      edit_grade(atoi(strs[2]), atoi(strs[3]), strs[4], atoi(strs[5]));
      //return
    }
    else
    {
      printf("Please enter a valid Edit command \n");
    }		
  }

  else if ( strcmp( strs[0], "delete" ) == 0 && num_args > 1 && num_args <= 5 )
  {
    if(strcmp( strs[1], "student") == 0 && num_args == 3 )
    {
      delete_student(strs[2]);
    }
    else if(strcmp( strs[1], "class") == 0 && num_args == 3 )
    {
      delete_class(atoi(strs[2]));
      //return;
    }
    else if(strcmp( strs[1], "assignment") == 0 && num_args == 4 )
    {
      delete_assignment(atoi(strs[2]), atoi(strs[3]));
    }
    else if(strcmp( strs[1], "grade") == 0 && num_args == 5 )
    {
      delete_grade(atoi(strs[2]), atoi(strs[3]), strs[4]);
    }
    else
    {
      printf("Please enter a valid delete command \n");
    }
  }

  else if ( strcmp( strs[0], "drop" ) == 0 && num_args > 1 && num_args <= 3)
  {
    if(num_args == 3)
    {
      drop_student(atoi(strs[1]), strs[2]);
      //return;
    }
    else
    {
      printf("Please enter a valid drop command \n");
    }
  }

  else if ( strcmp( strs[0], "view" ) == 0 )
  {
    if(strcmp( strs[1], "students") == 0 && num_args == 2 )
    {
      view_student_data_menu();
    }
    else if(strcmp( strs[1], "classes") == 0 && num_args == 2 )
    {
      view_class_data_menu();
    }
    else if(strcmp( strs[1], "assignments") == 0 && num_args == 3 )
    {
      view_assignment(atoi(strs[2]));
    }
    else if(strcmp( strs[1], "grades") == 0 && num_args == 4 )
    {
      if(strlen(strs[2]) != 9)
      {
	view_grade(atoi(strs[2]), atoi(strs[3]));
      }
      else
      {
	view_grade_student_ssn_cid(strs[2], atoi(strs[3]));
      }			
    }
    else if(strcmp(strs[1], "average") == 0 && strcmp( strs[2], "grade") == 0 && num_args == 5)
    {
      view_grade_aid_cid(atoi(strs[3]), atoi(strs[4]));
    }
    else
    {
      printf("Please enter a valid view command \n");
    }
  }
  else
  {
    printf("Please enter a valid command\n");
  } 
  //free(in);
  //free(strs);

  memset(in, 0, 1000); 
  memset(strs, 0, (sizeof (char*) * num_args));
  custom_command();
}
