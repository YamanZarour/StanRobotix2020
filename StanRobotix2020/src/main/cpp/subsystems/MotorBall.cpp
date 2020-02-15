/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/MotorBall.h"

MotorBall::MotorBall() {}

// This method will be called once per scheduler run
void MotorBall::Periodic()
{
    
}

void MotorBall::Propulsion(double force)
{
    motor.Set(force);
}
