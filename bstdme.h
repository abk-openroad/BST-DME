

/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/


#ifndef _BSTDME_H
#define _BSTDME_H

extern "C++"
{

#include  <string>

using namespace std;
class BstTree  ;

/**************************************************/
/**************************************************/
class BST_GenTestcase {
public:
  /*  generate a testcase of n sinks */
  static bool GenerateTestcase( unsigned n ) ;

} ;
/**************************************************/
/**************************************************/
class BST_DME 
{

public:
  enum DelayModelType 
  {
      LINEARMODEL  = 0,   
      ELMOREMODEL , 
      NumDelayModel          
  };

public:
  // constructor 
  BST_DME ( 
    const string &inputSinksFileName,
    const string &inputTopologyFileName,
    const string &inputObstructionFileName,
    double skewBound,
    DelayModelType delayModel ) ;

  // destructor 
  ~BST_DME() ; 

  /*************************************************/
  /* initiate the construction of BST */
  /*************************************************/
  void ConstructTree ( void ) ;

  /*************************************************/
  /* total length of the resulting BST after calling ConstructTree() ; */
  /*************************************************/
  double TotalLength ( void ) const ;

private:
// data:
   BstTree *m_bstdme ;
   
} ;

}
#endif

