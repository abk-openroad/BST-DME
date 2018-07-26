/****************************************************************************/
/* This software was written by C.-W. Albert Tsao  and is subject to:   */
/*                                                                          */
/*  Copyright (C) 1994-2000  by Andrew B. Kahng, C.-W. Albert Tsao         */
/*  Computer Science Department, University of California, Los Angeles. */
/****************************************************************************/

#ifndef _F_INTERVAL_H
#define _F_INTERVAL_H


#include "BiStates.h"
#include "BaseDefine.h"

extern "C++"
{
  template <class NN, class  NNDD, bool DOCHECK = true >
  class F_Interval {
  public: 

    /* constructor */
    F_Interval (void) { m_bound[Low] = 1; m_bound[High] = 0; }

    F_Interval ( NN a) { m_bound[Low] = a; m_bound[High] = a; }

    F_Interval ( NN a,  NN b) {
      m_bound[Low] = tMIN (a,b);
      m_bound[High] = tMAX (a,b);
    }

    F_Interval (const F_Interval& x) {
      m_bound[Low] = x.m_bound[Low];
      m_bound[High] = x.m_bound[High];
    }

    /* member function */
    bool
    IsEmpty (void) const {
        return m_bound[Low] > m_bound[High];
    }
    
    bool
    IsPoint (void) const {
       return m_bound[Low] == m_bound[High];
    }
    void Enclose (  NN n) {
      if ( IsEmpty() ) {
        m_bound[0]  = n ;
        m_bound[1]  = n ;
      } else {
        m_bound[Low]  = tMIN ( m_bound[Low], n ) ;
        m_bound[High] = tMAX ( m_bound[High], n ) ;
      }
    }

    void Enclose ( const F_Interval< NN, NNDD,DOCHECK>& p ) {
      if ( !p.IsEmpty() ) {
        Enclose ( p[Low] ) ;
        Enclose ( p[High] ) ;
      }
    }


    
    bool
    IsEnclose ( NN n) const {
        return n >= m_bound[Low] && n <= m_bound[High];
    }
    
    bool
    IsEnclose (const F_Interval< NN, NNDD,DOCHECK>& p) const {
        return p[Low] >= m_bound[Low] && p[High] <= m_bound[High];
    }
    
     NN Width (void) const {
        if (IsEmpty()) return 0;
        return m_bound[High] - m_bound[Low];
    }

    
    private:
     NN m_bound [2];
  } ;
} ;


#endif
