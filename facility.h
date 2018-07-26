/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/

#ifndef _F_FACILTY_H
#define _F_FACILTY_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
extern "C++"
{

/***********************************************************************/
/***********************************************************************/
void iDumpMsg ( const string &msg, ofstream &log, bool tocerr  ) ;
/***********************************************************************/
/***********************************************************************/
void iDumpOneLine ( ofstream &log, bool tocerr   ) ; 

/***********************************************************************/
/***********************************************************************/

string U_Printf( const char *fmt, ... );

/***********************************************************************/
/***********************************************************************/
void iShowTime() ;
/***********************************************************************/
/***********************************************************************/
void iRunTime() ;

}
#endif