/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include <commands/TankDriveJoystick.h>
#include <subsystems/DriveTrain.h>
#include <subsystems/Vision.h>
#include <frc/Joystick.h>
#include <Constants.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  double GetLeftJoystick();
  double GetRightJoystick();

 private:
  // The robot's subsystems and commands are defined here...
  DriveTrain m_driveTrain;
  Vision m_vision;
  TankDriveJoystick m_tankDriveJoystick;
  frc::Joystick m_joystick{kJoystick};

  void ConfigureButtonBindings();
};
