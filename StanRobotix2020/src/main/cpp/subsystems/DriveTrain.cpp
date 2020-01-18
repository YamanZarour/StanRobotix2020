/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {}

void DriveTrain::Drive(double left, double right)
{
    m_robotDrive.TankDrive(left, right);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
