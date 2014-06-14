#define EIGEN_DONT_PARALLELIZE
#define EPS 1e-15
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <time.h>
#include <math.h>
using namespace std;
using namespace Eigen;

template <typename NodeData>
struct quadtree{
   unsigned short int depth;
   unsigned short int position; //0 ul; 1 ur; 2 lr; 3 lr;
   double dx;
   double dy;
   double cx;
   double cy;
   bool is_leaf;

   std::array<quadtree<NodeData>*,4> children;
   std::array<quadtree<NodeData>*,4> nbrs;

//split a quadtree leaf into actualized quadtrees
   void split(quadrant) {
      auto ndx = dx/2;
      auto ndy = dy/2;
      std::array<double, 8> nc = {cx - ndx, cy + ndy, //upper left
            cx + ndx, cy + ndy,
            cx - ndx, cy - ndy, 
            cx + ndx, cy - ndy}
      for (auto i = 0; i<4; i++) {
         if (nbrs[i] != 0)
         {
            if (nbrs[i]->depth < depth) {
               nbrs[i].split();
            }
         }
         auto k = i - 1 % 4;
         if (nbrs[k] != 0) {
//3 situations: nbrs[k] is already coarser -> split it;
//then set its new nbrs to the current cell before splitting;
//then split current cell.
//OR nbrs[k] is the same depth; Do not split nbrs[k]; both children on the same
//side will share the same coarser nbr.
//OR nbrs[k] has one greater depth. Do not split. First split current cell;
//Then set the two children of nbrs[k]'s nbrs on the same side to the current cell;
            if (nbrs[k]->depth < depth) {
               split_lt(k);
            }
            else if (nbrs[k]->depth == depth)
         }





   void split_lt(k) {
      nbrs[k].split();

      
     





