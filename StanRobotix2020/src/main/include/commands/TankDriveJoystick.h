/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/DriveTrain.h>

class TankDriveJoystick
    : public frc2::CommandHelper<frc2::CommandBase, TankDriveJoystick> {
 public:
  explicit TankDriveJoystick(DriveTrain * driveTrain, std::function<double()> left,
               std::function<double()> right);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    DriveTrain * m_driveTrain;
    std::function<double()> m_left;
    std::function<double()> m_right;
};
