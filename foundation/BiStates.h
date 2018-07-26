
/****************************************************************************/
/* This software was written by C.-W. Albert Tsao  and is subject to:   */
/*                                                                          */
/*  Copyright (C) 1994-2000  by Andrew B. Kahng, C.-W. Albert Tsao         */
/*  Computer Science Department, University of California, Los Angeles. */
/****************************************************************************/

#ifndef _F_BISTATES_H 
#define _F_BISTATES_H 

extern "C++"
{
    typedef unsigned TwoStates;

    enum LowHigh {
        Low = 0,
        High = 1
    };

    enum XY {
        X = 0,
        Y = 1
    };

    enum YESNO {
        NO = 0,
        YES = 1
    };

}

#endif

