
/*

#**************************************************************************

***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************

*/


#include  <sys/times.h>
#include <sys/param.h>
#include <stdio.h>
#include "facility.h"

#define CPU_PER_SECOND  HZ
#define CPU_PER_MINUTE  (HZ * 60)


/***********************************************************************/
/***********************************************************************/
void iDumpMsg (
  const string &msg,
  ofstream &log,
  bool tocerr= false 
) {
  log << msg << endl ;
  if ( tocerr ) {
    cerr<< msg << endl ;
  }
} 
/***********************************************************************/
/***********************************************************************/
void iDumpOneLine (
  ofstream &log,
  bool tocerr= false 
) {
  log << endl ;
  if ( tocerr ) {
    cerr<< endl ;
  }
} 


/************************************************************************/
/*  Copyright (C) 1994/2000  by Chung-Wen Albert Tsao     */
/************************************************************************/
void iRunTime() {
static int lastSysTime = 0;
static int lastUserTime = 0;

struct tms      buffer;

  times(&buffer);
  unsigned umins = buffer.tms_utime - lastUserTime;

  lastUserTime = buffer.tms_utime;
  unsigned usecs = umins % CPU_PER_MINUTE;
  usecs /= CPU_PER_SECOND;
  umins /= CPU_PER_MINUTE;
  unsigned uhrs  = umins/60;
  umins = umins %60;

  unsigned smins = buffer.tms_stime - lastSysTime;

  lastSysTime = buffer.tms_stime;
  unsigned ssecs = smins % CPU_PER_MINUTE;
  ssecs /= CPU_PER_SECOND;
  smins /= CPU_PER_MINUTE;
  unsigned shrs  = smins/60;
  smins = smins %60;

  printf("User: [%02d:%02d:%02d ]\n", uhrs, umins, usecs);
  printf("Sys:  [%02d:%02d:%02d ]\n", shrs, smins, ssecs);
  printf("\n\n\n");
/*
  printf("CPU_PER_SECOND = %d\n", CPU_PER_SECOND);
  printf("CPU_PER_MINUTE = %d\n", CPU_PER_MINUTE);
*/
  return ;
}


/****************************************************************************/
/*  Display CPU time and current time.                                      */
/****************************************************************************/
void iShowTime() {
struct tms      buffer;

  times(&buffer);
  unsigned seconds = (buffer.tms_utime)/CPU_PER_SECOND;
  unsigned ss=seconds%60;
  unsigned minutes=seconds/60;
  unsigned mm=minutes%60;
  unsigned hours=minutes/60;
  unsigned hh=hours%24;
  unsigned days=hours/24;

  printf("Time:");
  if (days>0) { printf("%d:", days); }
  printf("%02d:%02d:%02d(%5d sec.)",hh,mm,ss, seconds);

  fflush(stdout);
}


#include <stdio.h>
#include <stdarg.h>
#include "assert.h"

/***********************************************************************/
/* a sprintf-like function that returns a C++ string */
/***********************************************************************/

string
U_Printf( const char *fmt, ... ) {

    const unsigned size = 60000;	// 60KB
    static char buf[size];

    buf[size-1] = '\0';			// mark the last position

    va_list ap;

    va_start( ap, fmt );
    vsprintf( buf, fmt, ap );
    va_end( ap );

    assert( buf[size-1] == '\0' );	// do not  run over

    return string( buf );

}

