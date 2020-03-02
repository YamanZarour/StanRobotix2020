/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/TankDriveJoystick.h"
#include "commands/PropulserBalle.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/Senseurs.h"
#include "subsystems/MotorBall.h"
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
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
  Senseurs * GetSenseurs();

 private:
  // The robot's subsystems and commands are defined here...
  DriveTrain m_driveTrain;
  Senseurs m_senseurs;
  TankDriveJoystick m_tankDriveJoystick;
  MotorBall m_motorBall;
  PropulserBalle m_propulserBalle;
  frc::Joystick m_joystick{kJoystick};
  frc2::JoystickButton m_buttonA{&m_joystick,kJoystickA};

  void ConfigureButtonBindings();
};
