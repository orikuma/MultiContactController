#pragma once

#include <TrajColl/CubicInterpolator.h>

#include <MultiContactController/State.h>

namespace MCC
{
/** \brief FSM state to initialize. */
struct InitialState : State
{
public:
  /** \brief Start. */
  void start(mc_control::fsm::Controller & ctl) override;

  /** \brief Run. */
  bool run(mc_control::fsm::Controller & ctl) override;

  /** \brief Teardown. */
  void teardown(mc_control::fsm::Controller & ctl) override;

protected:
  /** \brief Check whether state is completed. */
  bool complete() const;

protected:
  //! Phase
  int phase_ = 0;

  //! Base time to compute duration for autoStartTime
  double baseTime_ = 0.0;

  //! Function to interpolate task stiffness
  std::shared_ptr<TrajColl::CubicInterpolator<double>> stiffnessRatioFunc_;

  //! Stiffness of CoM task
  Eigen::Vector3d comTaskStiffness_ = Eigen::Vector3d::Zero();

  //! Stiffness of base link orientation task
  Eigen::Vector3d baseOriTaskStiffness_ = Eigen::Vector3d::Zero();

  //! Stiffness of momentum task
  Eigen::Vector6d momentumTaskStiffness_ = Eigen::Vector6d::Zero();
};
} // namespace MCC
