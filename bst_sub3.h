

/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/

#ifndef _BST_SUB3_H
#define _BST_SUB3_H


typedef struct obstacletype {
  int n_vertex;
  PointType vertex[4];
} ObstacleType;

typedef struct treenodetype {
  double bbox[4];
  int parent, L, R, id, level;
} TreeNodeType;



void read_obstacle_file( const string &fn) ;
void print_obstacles( const string &fn) ;

int line_into_rectangle (PointType  *p0, PointType *p1, 
   ObstacleType * block) ;
void print_path(FILE *f, PointType path[], int n) ;

int modify_blocked_areas_no_detour(AreaType *area, AreaType new_area[]) ;

#endif

