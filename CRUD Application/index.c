#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"clear_buffer.h"
#include "structs.h"
#include "viewstudent.h"
#include "viewclass.h"
#include "viewassignment.h"
#include "viewgrade.h"
#include "viewenrollment.h"
#include "viewclassavggrade.h"
#include "viewstudentavggrade.h"
#include "viewavgcidaid.h"
#include "viewscid.h"
#include "addstudent.h"
#include "addclass.h"
#include "addassignment.h"
#include "addgrades.h"
#include "enrollstudent.h"
#include "editstudent.h"
#include "editclass.h"
#include "editassignment.h"
#include "editgrade.h"
#include "deletestudent.h"
#include "deleteclass.h"
#include "deleteassignment.h"
#include "deletegrade.h"
#include "dropstudent.h"
#include "customcommands.h"
#include "commandline.h"
#include "menu.h"



int main(int argc, char * argv[])
{
  if(argc == 1)
  {
    main_menu();
  }
  else
  {
    command_line(argc, argv);
  }
  return 0;
}
