#ifndef problem_source_H
#define problem_source_H

#include <prob_parameters.H>

using namespace amrex;

constexpr Real p_orb_vel = 1.e-3_rt;
constexpr Real p_radius = 1.e10_rt;
constexpr Real beta = p_orb_vel * 2.0_rt / p_radius;

AMREX_GPU_HOST_DEVICE AMREX_INLINE
void problem_source (int i, int j, int k,
                     GeometryData const& geomdata,
                     Array4<const Real> const& state,
                     Array4<Real> const& src,
                     const Real dt, const Real time)
{
    using namespace problem;

    const Real* problo = geomdata.ProbLo();
    const Real* dx = geomdata.CellSize();

    for (auto n = 0; n < NSRC; ++n) {
        src(i,j,k,n) = 0.0_rt;
    }

    auto y = problo[1] + dx[1]*(Real(j) + 0.5_rt) - center[1];
    auto ang_vel = 0.5 * beta * y;

#if AMREX_SPACEDIM == 3
    src(i,j,k,UMX) += 2.0_rt * state(i,j,k,UMY) * ang_vel;
    src(i,j,k,UMY) += - 2.0_rt * state(i,j,k,UMX) * ang_vel;
#endif
}

#endif
