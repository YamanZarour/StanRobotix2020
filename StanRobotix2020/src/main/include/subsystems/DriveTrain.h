/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMTalonSRX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void Drive(double left, double right);

 private:
  WPI_TalonSRX m_L1{kMotorL1};
  WPI_TalonSRX m_L2{kMotorL2};
  WPI_TalonSRX m_R1{kMotorR1};
  WPI_TalonSRX m_R2{kMotorR2};
  frc::SpeedControllerGroup m_left{m_L1, m_L2};
  frc::SpeedControllerGroup m_right{m_R1, m_R2};
  frc::DifferentialDrive m_robotDrive{m_left, m_right};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
