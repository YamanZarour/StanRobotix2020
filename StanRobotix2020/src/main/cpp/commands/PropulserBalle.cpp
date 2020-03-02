/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PropulserBalle.h"
#include "Robot.h"

PropulserBalle::PropulserBalle(MotorBall *motorBall, double force) : m_motorBall(motorBall), m_force(force)
{
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements({motorBall});
}

// Called when the command is initially scheduled.
void PropulserBalle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PropulserBalle::Execute()
{
  //std::cout<<"testing"<<std::endl;
  m_motorBall->Propulsion(Robot::motorBallForce);
}

// Called once the command ends or is interrupted.
void PropulserBalle::End(bool interrupted) {}

// Returns true when the command should end.
bool PropulserBalle::IsFinished() { return false; }
