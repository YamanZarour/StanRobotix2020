/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TestCamera.h"

TestCamera::TestCamera() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TestCamera::Initialize() 
{
  m_Vision->Initialization();
}

// Called repeatedly when this Command is scheduled to run
void TestCamera::Execute()
{
  m_Vision->GetAngle();
}

// Called once the command ends or is interrupted.
void TestCamera::End(bool interrupted) {}

// Returns true when the command should end.
bool TestCamera::IsFinished() { return false; }
