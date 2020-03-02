/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

//#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc2/command/CommandScheduler.h>

#include <iostream>
using namespace std;

double Robot::motorBallForce = 0.5;

void Robot::RobotInit() {
  prefs = frc::Preferences::GetInstance();
	motorBallForce = prefs->GetDouble("motorBallForce", 0.5);
  m_senseur.Calibrate();
  m_imu.Calibrate();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
  prefs = frc::Preferences::GetInstance();
	motorBallForce = prefs->GetDouble("motorBallForce", 0.7);}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {

  
  // cout << endl << endl << m_senseur.GetAngleX() << endl << endl;

  

    //*Camera = Server->GetInstance()->StartAutomaticCapture();
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
  
  //m_moterBall.Propulsion(-0.8);

  m_imu.SetYawAxis(frc::ADIS16448_IMU::IMUAxis::kX);
  m_imu.Calibrate();
  //m_container.GetSenseurs()->ResetEncoders();
  //m_testCameraCommand->Initialize();

  

  //*Camera = Server->GetInstance()->StartAutomaticCapture();

  //mNetworkTableInstanceInst = nt::NetworkTableInstance::GetDefault();

}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  
  motor1.Set(0.2);

  /*
  cout << endl << endl;
  cout << (m_imu.GetAccelInstantX()) / 1200 << ";";
  cout << (m_imu.GetAccelInstantY()) / 1200 << ";";
  cout << (m_imu.GetAccelInstantZ()) / 1200 << ";";
  cout << accel.GetX() << ";";
  cout << accel.GetY() << ";";
  cout << accel.GetZ() << endl;
  */

  //cout<<endl<<endl<< (m_imu.GetAccelInstantZ() * 9.81) / 1200 <<endl<<endl;
  /*
  Server.GetInstance()->StartAutomaticCapture();
  cvSink = Server.GetVideo();
  outputStream = Server.PutVideo("Blur", 640, 480);
  */

  //std::cout<<"Left side : "<<m_container.GetSenseurs()->GetLeftEncoder()<<std::endl;
  //std::cout<<"Right side : "<<m_container.GetSenseurs()->GetRightEncoder()<<std::endl;
  //std::cout<<std::endl;
   
  // tempMotor.Set(tempJoystick.GetRawAxis(1));
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
