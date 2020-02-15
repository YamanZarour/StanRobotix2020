/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//
//
//  PAS LE FINAL
//  S'INSPIRER
//
//

#include "subsystems/Vision.h"
#include "Constants.h"
#include <iostream>


//Vision::Vision() : Subsystem("Vision")
//{

//}

Vision::Vision()
{
    
}

void Vision::Initialization() 
{
    foundLine = true;
    foundContour = true;

    //cs::UsbCamera TESTUsbCamera("USB Camera 0", 0);

    //cs::MjpegServer mjpegServer1("serve_USB Camera 0", 1181);
    //mjpegServer1.SetSource(TESTUsbCamera);

    //cs::CvSink cvSink("opencv_USB Camera 0");
    //cvSink.SetSource(TESTUsbCamera);

    
// Creates the CvSource and MjpegServer [2] and connects them
    //cs::CvSource outputStream("Blur", cs::VideoMode::PixelFormat::kMJPEG, 640, 480, 30);
    //cs::MjpegServer mjpegServer2("serve_Blur", 1182);
    //mjpegServer2.SetSource(outputStream);
/*
    USBCamera.GetInstance.StartAutomaticCapture();
    USBCameraVideo = USBCamera.GetInstance.GetVideo();
    USBCameraSource = USBCamera.GetInstance.PutVideo("CHOSE", 640, 480);
    
    */ 

    *Camera = Server->GetInstance()->StartAutomaticCapture();

    mNetworkTableInstanceInst = nt::NetworkTableInstance::GetDefault();
    lastAngle = 90;
}

double Vision::GetAngle()
{
    auto table = mNetworkTableInstanceInst.GetTable("GRIP/myLinesReport");
    auto wAngle = table->GetEntry("angle").GetDoubleArray(0);

    //auto LinesOutput = Pipeline->GetFilterLinesOutput();
    

    for (int i = 0; i < wAngle.size(); i++)
    {
        std::cout << wAngle[i];
    }

    return 0;       //temporaire
}

// This method will be called once per scheduler run
void Vision::Periodic() {}
