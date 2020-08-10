void command_line(int length, char *args[])
{
  int val = 0;
  int i = 1;
  int j = 0;
  char par1[30];
  char par2[30];
  char par3[30];
  char par4[30];
  strcpy(par1, "NULL");
  strcpy(par2, "NULL");
  strcpy(par3, "NULL");
  strcpy(par4, "NULL");

  for(i = 1; i < 2; i++)
  {
    for(j = 0; args[i][j]; j++)
    {
      args[i][j] = tolower(args[i][j]);
    }
  }

  if(length == 8 && strcmp( args[1], "-add-student" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-f" ) == 0 || strcmp( args[i], "-l" ) == 0 || strcmp( args[i], "-s" ) == 0)
      {
	if(strcmp( args[i], "-f" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }	
        else if(strcmp( args[i], "-l" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      add_student(par1, par2, par3);
    }      
  }

  else if ( length == 4 && strcmp( args[1], "-add-class" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-t" ) == 0)
      {
	strcpy(par1, args[i+1]);
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    add_class(par1);
  }

  else if ( length == 8 && strcmp( args[1], "-add-assignment" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-t" ) == 0 || strcmp( args[i], "-p" ) == 0)
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }	
        else if(strcmp( args[i], "-t" ) == 0 )
	{
	  strcpy(par2, args[i+1]);
        }
        else if(strcmp( args[i], "-p" ) == 0 )
	{
	  strcpy(par3, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      add_assignment(atoi(par1), par2, atoi(par3));
    }    
  }

  else if ( length == 10 && strcmp( args[1], "-add-grade" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-p" ) == 0)
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }	
        else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }	
        else if(strcmp( args[i], "-p" ) == 0 )
        {
	  strcpy(par4, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      add_grade(atoi(par1), atoi(par2), par3, atoi(par4));	  
    }    
  }

  else if ( length == 6 && strcmp( args[1], "-enroll" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-s" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
        else if(strcmp( args[i], "-s" ) == 0 )
	{
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      enroll_student(atoi(par1), par2);
    }
  }

  else if(length == 8 && strcmp( args[1], "-edit-student" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-f" ) == 0 || strcmp( args[i], "-l" ) == 0)
      {
	if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-f" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-l" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      edit_student(par2, par3, par1);
    }    
  }

  else if(length == 6 && strcmp( args[1], "-edit-class" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-t" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }	
        else if(strcmp( args[i], "-t" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      edit_class(atoi(par1), par2);
    }   
  }

  else if(length == 10 && strcmp( args[1], "-edit-assignment" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-t" ) == 0 || strcmp( args[i], "-p" ) == 0)
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-t" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }
        else if(strcmp( args[i], "-p" ) == 0 )
        {
	  strcpy(par4, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      edit_assignment(atoi(par1), atoi(par2), par3, atoi(par4));	  
    }    
  }

  else if ( length == 10 && strcmp( args[1], "-edit-grade" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-p" ) == 0)
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }
	else if(strcmp( args[i], "-p" ) == 0 )
        {
	  strcpy(par4, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
	return;
      }
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0  || strcmp( par4, "NULL" ) == 0)
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      edit_grade(atoi(par1), atoi(par2), par3, atoi(par4));	  
    }    
  }

  else if ( length == 4 && strcmp( args[1], "-delete-student" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-s" ) == 0)
      {
	strcpy(par1, args[i+1]);   
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    delete_student(par1);
  }

  else if ( length == 4 && strcmp( args[1], "-delete-class" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0)
      {
	strcpy(par1, args[i+1]);   
      }
      else
      {
	printf("Please type a valid command\n");
	return;
      }
    }
    delete_class(atoi(par1));
  }

  else if(length == 6 && strcmp( args[1], "-delete-assignment" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      delete_assignment(atoi(par1), atoi(par2));
    }    
  }

  else if ( length == 8 && strcmp( args[1], "-delete-grade" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 || strcmp( args[i], "-s" ) == 0)
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
	else if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par3, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 || strcmp( par3, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      delete_grade(atoi(par1), atoi(par2), par3); 
    }    
  }

  else if ( length == 6 && strcmp( args[1], "-drop" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-s" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-s" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
	return;
      }
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      drop_student(atoi(par1), par2);	  
    }       
  }

  else if ( length == 2 && strcmp( args[1], "-view-s" ) == 0  )
  {
    view_student_data_menu();
  }

  else if ( length == 2 && strcmp( args[1], "-view-c" ) == 0  )
  {
    view_class_data_menu();
  }

  else if ( length == 4 && strcmp( args[1], "-view-a" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0)
      {
	strcpy(par1, args[i+1]);   
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      view_assignment(atoi(par1));
    }
  }

  else if ( length == 6 && strcmp( args[1], "-view-g" ) == 0  && strcmp(args[2], "-cid") == 0 )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }
	else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      view_grade(atoi(par1), atoi(par2));
    }    
  }
  
  else if ( length == 6 && strcmp( args[1], "-view-g" ) == 0 &&  strcmp(args[2], "-s") == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-s" ) == 0 || strcmp( args[i], "-cid" ) == 0 )
      {
	if(strcmp( args[i], "-s" ) == 0 )
      	{
	  strcpy(par1, args[i+1]);
       	}
	
        else if(strcmp( args[i], "-cid" ) == 0 )
	{
       	  strcpy(par2, args[i+1]);
	}
      }
      else
      {
	printf("Please type a valid command\n");
	return;
      }
    }

    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
    }
    else
    {
      view_grade_student_ssn_cid(par1, atoi(par2));
    }
  }    

  else if ( length == 6 && strcmp( args[1], "-view-g-avg" ) == 0  )
  {
    for(i = 2; i < length; i = i + 2 )
    {
      if(strcmp( args[i], "-cid" ) == 0 || strcmp( args[i], "-aid" ) == 0 )
      {
	if(strcmp( args[i], "-cid" ) == 0 )
        {
	  strcpy(par1, args[i+1]);
        }	
        else if(strcmp( args[i], "-aid" ) == 0 )
        {
	  strcpy(par2, args[i+1]);
        }
      }
      else
      {
	printf("Please type a valid command\n");
        return;
      } 
    }
    if(strcmp( par1, "NULL" ) == 0 || strcmp( par2, "NULL" ) == 0 )
    {
      printf("Please type a valid command\n");
      return;
    }
    else
    {
      view_grade_aid_cid(atoi(par1), atoi(par2));
    }    
  }

  else
  {
    printf("Please type a valid command\n");
  }
}
