
/****************************************************************************/
/* This software was written by C.-W. Albert Tsao  and is subject to:   */
/*                                                                          */
/*  Copyright (C) 1994-2000  by Andrew B. Kahng, C.-W. Albert Tsao         */
/*  Computer Science Department, University of California, Los Angeles. */
/****************************************************************************/
#ifndef _F_BOX_H
#define _F_BOX_H

#include "BiStates.h"
#include "BaseDefine.h"
#include "Coordinate.h"

extern "C++"
{

  template <typename NN, typename NNDD, bool DOCHECK>
  class F_Box
    {
    public:
        F_Box (void) {}        // Empty ranges
       
        template <bool CK>
        F_Box (const F_Coord<NN,NNDD,CK>& p) {
            m_range[0] = p[X];
            m_range[1] = p[Y];
        }
    }

};

#endif
