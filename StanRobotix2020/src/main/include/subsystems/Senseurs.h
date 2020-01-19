/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>
#include <Constants.h>

class Senseurs : public frc2::SubsystemBase {
 public:
  Senseurs();
  double GetLeftEncoder();
  double GetRightEncoder();
  void ResetEncoders();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
 frc::Encoder leftEncoder{2,3, true}; //inverse
 frc::Encoder rightEncoder{0,1, false}; //bon cote
};
