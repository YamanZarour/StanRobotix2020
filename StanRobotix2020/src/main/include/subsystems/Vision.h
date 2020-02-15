/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <cscore.h>
#include <cscore_cv.h>
#include <cameraserver/CameraServer.h>
//#include <GRIP/GripPipeline.h>

class Robot;

class Vision : public frc2::SubsystemBase {
 public:
  Vision();

  cs::UsbCamera *Camera;
  frc::CameraServer *Server;
  //grip::GripPipeline *Pipeline;

  //cs::MjpegServer mjpegServer1;
  //cs::CvSink cvSink;
  //cs::CvSource outputStream;
  //cs::MjpegServer mjpegServer2;

  void Initialization(); 

  double GetContoursCentreX();
  double GetAngle();
  double GetContourAngle();
  double GetLineAngle();
  void GetLine(double * oLine);

  bool FoundContour();
  bool FoundLine();

  void DisplayData(); 

  double GetX1();
  double GetX2();
  double GetY1();
  double GetY2();

  double GetRightAngle();
  double GetLeftAngle();

  void ReadyData();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  bool foundContour;
  bool foundLine;
  double lastAngle;
  nt::NetworkTableInstance mNetworkTableInstanceInst;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
