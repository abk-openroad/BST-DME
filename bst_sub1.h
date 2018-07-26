/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/


#ifndef _BST_SUB1_H
#define _BST_SUB1_H

void ShowTime() ;

void print_Point(FILE *f, const PointType& pt) ;

void read_input_file( const string &fn );
void print_merging_tree( const char fn[], int v);
void print_bst(const char fn[], int v, double TCost, double Tdist);
void read_input_topology ( const string &fn ) ;
void print_topology(const char fn[], int v, double TCost, double Tdist);
void RunTime() ;
int equal(double x,double y) ;

void print_clustering_info();


void check_JS_MS() ;
double ms_distance(TrrType *ms1,TrrType *ms2) ;

void ms2line(TrrType *ms, PointType *p1, PointType *p2) ;

double calc_boundary_length(AreaType *area) ;

int Manhattan_arc(PointType p1,PointType p2) ;

void make_Point_TRR(PointType p, TrrType *trr) ;

int areaJS_line_type(AreaType *area) ;
void print_area(AreaType *area) ;
void print_area_info(AreaType *area) ;
void assign_NodeType(NodeType *node1, NodeType *node2) ;

void calc_merge_distance(double r,double c, double cap1,double delay1,
      double cap2, double delay2, double d,double *d1,double *d2)  ;


#endif

