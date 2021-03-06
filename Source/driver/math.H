#ifndef CASTRO_MATH_H
#define CASTRO_MATH_H

#include <AMReX_REAL.H>
#include <AMReX_Array.H>

AMREX_GPU_HOST_DEVICE AMREX_INLINE
void
cross_product(amrex::GpuArray<amrex::Real, 3> const& a,
              amrex::GpuArray<amrex::Real, 3> const& b,
              amrex::GpuArray<amrex::Real, 3>& c) {

  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = a[2] * b[0] - a[0] * b[2];
  c[2] = a[0] * b[1] - a[1] * b[0];

}

#endif
