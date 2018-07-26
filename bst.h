/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/


#ifndef _BST_H
#define _BST_H

#include "bst_header.h"


double BME_merging_cost(NodeType *node_L, NodeType *node_R) ;

int ExG_DME (int n_trees, int v, int show_info) ;
void MergeArea(AreaType  *area,AreaType  *area_L,
       AreaType  *area_R,int mode) ;

void MergeArea_sub(AreaType  *area) ;

void init_clusters(int L, int PostOpt) ;

#endif

