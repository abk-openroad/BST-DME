
/****************************************************************************/
/* This software was written by C.-W. Albert Tsao  and is subject to:   */
/*                                                                          */
/*  Copyright (C) 1994-2000  by Andrew B. Kahng, C.-W. Albert Tsao         */
/*  Computer Science Department, University of California, Los Angeles. */
/****************************************************************************/
#ifndef _F_COORD_H
#define _F_COORD_H

#include "BiStates.h"
#include "BaseDefine.h"

extern "C++"
{

  // NN  is a data type used for the coordinates.
  // NNDD is a type with a larger precision.
  template <class NN, class NNDD, bool DOCHECK = true>
  class F_Coord
  {

    private:
        NN  m_coord [ 2] ;
    public:
        // constructor 
        F_Coord (NN  x, NN  y ) {
          m_coord[ 0] = x, m_coord[ 1 ] = y;
        } ;

        F_Coord (const F_Coord& p2) {
            m_coord[0] = p2.m_coord[0];
            m_coord[1] = p2.m_coord[1];
        } ;

        // member function  
        NN  operator[] ( TwoStates i) const {
            return m_coord[i];
        } ;
    } ;
    template <class NN, class NNDD, bool DOCHECK = true>
    class F_Point {
    public:
      F_Point () {
        x=y=0;
        max=min=0;
        t=0 ;
      } ;
      NN     x,y;   /* coordinate */ 
      NN     max, min;  /* (max, min) delays after merging */
      NN     t;    /* usded for sorting */
    } ;

}
#endif
