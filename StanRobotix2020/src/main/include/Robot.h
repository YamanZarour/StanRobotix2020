/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include <frc/Spark.h>
#include <frc/Joystick.h>

#include "RobotContainer.h"

#include <cscore.h>
#include <cscore_cv.h>
#include <cameraserver/CameraServer.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Senseurs.h"

#include "frc/Preferences.h"

#include <adi/ADIS16448_IMU.h>

#include <frc/BuiltInAccelerometer.h>

class Robot : public frc::TimedRobot {
 public:

  ~Robot();
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  static double motorBallForce;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;
  
  cs::UsbCamera Camera;
  frc::CameraServer Server;
  //nt::NetworkTableInstance mNetworkTableInstanceInst;
  cs::CvSink cvSink;
  cs::CvSource outputStream;

  frc::Preferences* prefs;

  Senseurs m_senseur;
  DriveTrain m_drivetrain;
  MotorBall m_moterBall;

  frc::BuiltInAccelerometer accel;

  RobotContainer m_container;
  frc::Spark tempMotor{9};
  frc::Joystick tempJoystick{0};

  WPI_TalonSRX motor1;

  frc::ADIS16448_IMU m_imu{};
};
