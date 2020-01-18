/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_tankDriveJoystick(&m_driveTrain, [this]{return GetLeftJoystick();}, [this]{return GetRightJoystick();}) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}

double RobotContainer::GetLeftJoystick()
{
  return -m_joystick.GetRawAxis(kJoystickL);
}

double RobotContainer::GetRightJoystick()
{
  return -m_joystick.GetRawAxis(kJoystickR);
}
