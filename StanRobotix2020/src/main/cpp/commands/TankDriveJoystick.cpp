/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TankDriveJoystick.h"

TankDriveJoystick::TankDriveJoystick(DriveTrain* driveTrain, std::function<double()> left,
               std::function<double()> right) : m_driveTrain(driveTrain), m_left(left), m_right(right) {
  AddRequirements({driveTrain});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TankDriveJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDriveJoystick::Execute() {
  m_driveTrain->Drive(m_left(), m_right());
}

// Called once the command ends or is interrupted.
void TankDriveJoystick::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDriveJoystick::IsFinished() { return false; }
