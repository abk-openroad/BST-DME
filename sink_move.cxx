

/*
#**************************************************************************
#**   Please read README to see how to run this program
***   Created by Chung-Wen Albert Tsao  on May 2, 2000*
#**
#**
#**************************************************************************
*/


#include "bst_header.h"
#include "Global_var.h"

extern double pt2ms_distance(PointType *pt, TrrType *ms);

extern void make_intersect( TrrType *trr1, TrrType *trr2, TrrType *t );
extern void core_mid_point(TrrType *trr, PointType *p);
extern void make_core(TrrType *trr,TrrType *core);


/********************************************************************/
/*                                                                  */
/********************************************************************/
int sink_move_compare_inc(const void *a, const void *b) {

   PairType *p = (PairType *) a;
   PairType *q = (PairType *) b;

   return( (p->cost > q->cost) ? YES: NO);
}

/********************************************************************/
/*                                                                  */
/********************************************************************/
void _calc_cluster_center(int cid, TrrType *ms) {
TrrType temp;

  double r = INT_MAX;
  unsigned n = 0; 
  unsigned npoints = gBoundedSkewTree->Npoints() ;
  for (unsigned i=0;i<npoints;++i) {
    PointType &qt = Node[ i   ].m_stnPt ;
    if (cid == Cluster_id[i]) {
      if (n==0) {
        ms->MakeDiamond (  qt     , r);
      } else {
        temp.MakeDiamond (  qt     , r);
        make_intersect(ms, &temp, ms);
      }
      n++;
    }
  }
  make_core(ms, ms);
}

/********************************************************************/
/*  calc neighbors of cluster cid.                                  */
/********************************************************************/
int _calc_cluster_neighbors(int cid, PairType pair[], int size) {
int i, n;
TrrType ms;

  n = 0;
  _calc_cluster_center(cid,  &ms);
  int nterms = (int) gBoundedSkewTree->Nterms() ;
  for (i=0;i<nterms;++i) {
    if (Cluster_id[i]!=cid) {
      pair[n].x = i;
      pair[n].y = cid;
      PointType &qt = Node[ i   ].m_stnPt ;
      pair[n].cost = pt2ms_distance(&(  qt     ), &ms);
      n++;
    }
  }
  assert(n>0 && n <= MAX_N_NODES);
  qsort(pair, n, sizeof(PairType), sink_move_compare_inc);
  n = min (n, size);
  return(n);
}

/********************************************************************/
/*                                                                  */
/********************************************************************/
int calc_all_cluster_neighbors(PairType pair[], int n_clusters, int size) {
int i,j,m, n;
PairType temp[MAX_N_NODES];

  n = 0;
  for (i=0;i< n_clusters;++i) {
    m = _calc_cluster_neighbors(i,temp, size);
    for (j=0;j<m;++j) {
      pair[n++] = temp[j];
    }
  }
  assert(n>0 && n <= MAX_N_NODES);
  qsort(pair, n, sizeof(PairType), sink_move_compare_inc);
  n = min (n, size*n_clusters);
  return(n);
}

