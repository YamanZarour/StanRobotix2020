/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Senseurs.h"
#include <math.h>

Senseurs::Senseurs() {
    leftEncoder.Reset();
    rightEncoder.Reset();
    leftEncoder.SetDistancePerPulse(kWheelDiameter*M_PI/kPulsesPerRev);
    rightEncoder.SetDistancePerPulse(kWheelDiameter*M_PI/kPulsesPerRev);
}

// This method will be called once per scheduler run
void Senseurs::Periodic() {}

double Senseurs::GetLeftEncoder()
{
    // valeur est inferieure a celle attendue
    return leftEncoder.GetDistance();
}

double Senseurs::GetRightEncoder()
{
    return rightEncoder.GetDistance();
}

void Senseurs::ResetEncoders()
{
    leftEncoder.Reset();
    rightEncoder.Reset();
}

double Senseurs::GetAngleX()
{
    return imu.GetGyroAngleX();
}

double Senseurs::GetAccelX()        // Instant
{
    return imu.GetAccelInstantX();
}

double Senseurs::GetAccelY()        // Instant
{
    return imu.GetAccelInstantY(); 
}

double Senseurs::GetAccelZ()        // Instant
{

    return imu.GetAccelInstantZ();
}

void Senseurs::Calibrate()
{
    imu.Calibrate();
}
