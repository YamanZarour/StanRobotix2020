/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include "Constants.h"


class MotorBall : public frc2::SubsystemBase {
 public:
  MotorBall();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void Propulsion(double force);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::Spark motor{kMotorBall};
};