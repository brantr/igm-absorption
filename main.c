#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "igm-absorption.h"

int main(int argc, char **argv)
{
  int i;
  double lmin = 3000; //angstrom observed
  double lmax = 9000; //angstrom observed
  double *l;
  double *T;
  int nl = 1000;
  int nz = 1000;
  double zmin = 0;
  double zmax = 8.0;
  double la;
  double z;

  l = (double *) calloc(nl,sizeof(double));
  for(i=0;i<nl;i++)
    l[i] = (lmax-lmin)*((double) i)/((double) (nl-1)) + lmin;


/*
  //redshift 2
  z = 2.0;
  print_igm_absorption(l, nl, z);

  //redshift 3
  z = 3.0;
  print_igm_absorption(l, nl, z);

  //redshift 4
  z = 4.0;
  print_igm_absorption(l, nl, z);

  //redshift 5
  z = 5.0;
  print_igm_absorption(l, nl, z);

  //redshift 6
  z = 6.0;
  print_igm_absorption(l, nl, z);
*/
  for(i=0;i<nz;i++)
  {
    z = (zmax-zmin)*((double) i)/((double)(nz-1)) + zmin;
    la = 1215.66*(1+z);
    printf("%e\t%e\t%e\n",z,la,exp(-1*tau_IGM(la,z)));
  }


  return 0;
}