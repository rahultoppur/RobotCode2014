// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
#include"Commands/TurnVarAngle.h"
#include"Commands/LightControl.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveBack.h"
#include "Commands/DriveBackAndForth.h"
#include "Commands/DriveForward.h"
#include "Commands/DriveInSquare.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/LightControl.h"
#include "Commands/RunTest.h"
#include "Commands/TurnAngle.h"
#include "Commands/TurnLeft.h"
#include "Commands/TurnRight.h"
#include "Commands/TurnWithVision.h"
#include "Commands/RunCatapultTest.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftGear.h"
#include "Commands/ShiftUp.h"
const double OI::PotRange = 3.2;
OI::OI() {
	// Process operator interface input here.
	m_leftStick = new Joystick(2);
	m_rightStick = new Joystick(1);
	m_gameStick = new Joystick(3);

	
    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("RunTest", new RunTest());
	SmartDashboard::PutData("DriveBackAndForth", new DriveBackAndForth());
	SmartDashboard::PutData("DriveInSquare", new DriveInSquare());

	SmartDashboard::PutData("TurnVarAngle", new TurnVarAngle());
	screen = DriverStationLCD::GetInstance();
//	m_enhancedIO = DriverStation::GetInstance()->GetEnhancedIO()
	
	m_rightTrigger = new JoystickButton(m_rightStick, 1);
	m_leftTrigger = new JoystickButton(m_leftStick, 1);

	m_rightButton2 = new JoystickButton(m_rightStick, 2);
	m_rightButton3 = new JoystickButton(m_rightStick, 3);
	m_rightButton4 = new JoystickButton(m_rightStick, 4);
	m_rightButton5 = new JoystickButton(m_rightStick, 5);
	m_rightButton6 = new JoystickButton(m_rightStick, 6);
	m_rightButton7 = new JoystickButton(m_rightStick, 7);
	m_rightButton8 = new JoystickButton(m_rightStick, 8);
	m_rightButton9 = new JoystickButton(m_rightStick, 9);
	m_rightButton10 = new JoystickButton(m_rightStick, 10);
	m_rightButton11 = new JoystickButton(m_rightStick, 11);
	
	m_leftButton3 = new JoystickButton(m_leftStick, 3);
	m_leftButton4 = new JoystickButton(m_leftStick, 4);
	m_leftButton5 = new JoystickButton(m_leftStick, 5);
	m_leftButton6 = new JoystickButton(m_leftStick, 6);
	m_leftButton7 = new JoystickButton(m_leftStick, 7);
	m_leftButton8 = new JoystickButton(m_leftStick, 8);
	m_leftButton9 = new JoystickButton(m_leftStick, 9);
	m_leftButton10 = new JoystickButton(m_leftStick, 10);
	
	m_gameButton1 = new JoystickButton(m_gameStick, 1);
	m_gameButton2 = new JoystickButton(m_gameStick, 2);
	m_gameButton3 = new JoystickButton(m_gameStick, 3);
	m_gameButton4 = new JoystickButton(m_gameStick, 4);
	m_gameButton5 = new JoystickButton(m_gameStick, 5);
	m_gameButton6 = new JoystickButton(m_gameStick, 6);
	m_gameButton7 = new JoystickButton(m_gameStick, 7);
	m_gameButton8 = new JoystickButton(m_gameStick, 8);
	
	//assign events to buttons
//	m_rightButton2->WhenPressed(new Autonomous1());
	m_rightButton3->WhenPressed(new TurnWithVision());
	m_rightButton4->WhenPressed(new TurnAngle(-45.0, TURNANGLETOLERENCE, TURNANGLEDELTA, TURNANGLEZONE, COMPENSATION, 2));
	m_rightButton5->WhenPressed(new TurnAngle(45.0, TURNANGLETOLERENCE, TURNANGLEDELTA, TURNANGLEZONE, COMPENSATION, 2));
	m_leftTrigger->WhenPressed(new DriveWithJoysticks());
	m_rightButton8->WhenPressed(new LightControl(true));
	m_rightButton9->WhenPressed(new LightControl(false));
//	m_rightButton11->WhenPressed(new RetractPiston());
	m_rightTrigger->WhileHeld(new RunCatapultTest(0, 0));
	m_rightButton6->WhenPressed(new RunCatapultTest(0, 0.2));
	m_rightButton7->WhenPressed(new RunCatapultTest(0, 0.4));
	m_rightButton10->WhenPressed(new RunCatapultTest(0, 0.7));
	m_rightButton11->WhenPressed(new RunCatapultTest(0, 1));
	
	m_leftButton3->WhenPressed(new ShiftGear());
	m_leftButton4->WhenPressed(new ShiftDown());
	m_leftButton5->WhenPressed(new ShiftUp());
}

Joystick* OI::getm_leftStick() {
	return m_leftStick;
}
Joystick* OI::getm_rightStick() {
	return m_rightStick;
}
float OI::getCrouch(){
	float crouch;
	crouch = m_rightStick->GetZ();
	crouch = 1-crouch;
	crouch = crouch/2;
	return crouch;
}
void OI::printCrouch(){
	double crouch = getCrouch();
	screen->PrintfLine(DriverStationLCD::kUser_Line1, "Crouch: %f", crouch);

}
void OI::printAngle(){
	screen->PrintfLine(DriverStationLCD::kUser_Line2, "Bngle: %f", CommandBase::chassis->m_gyro->PIDGet()*180);
}
OI::AutonomousVariant OI::getAutonomousVariant(){
	OI::AutonomousVariant ret = AV_NONE;
	
	
	if (!(DriverStation::GetInstance()->GetEnhancedIO().GetDigital(2)))
	{
		ret = AV_2;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(4)){
		ret = AV_4;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(6)){
		ret = AV_6;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(8)){
		ret = AV_8;
	}
	
	return ret;
	
}
void OI::printVariant(){
	screen->PrintfLine(DriverStationLCD::kUser_Line6, "Variant: %d", getAutonomousVariant());
}
//#define NOENCHANCEDIO 1
float OI::getCatapultSpeed(){
	float catapultspeed;
#ifdef NOENCHANCEDIO
	catapultspeed = m_leftStick->GetZ();
	catapultspeed = 1-catapultspeed;
	catapultspeed = catapultspeed/2;
#else
	catapultspeed = DriverStation::GetInstance()->GetAnalogIn(2)/PotRange;
	catapultspeed = round(catapultspeed, 0.01);
#endif
	return catapultspeed;	
}





void OI::printTargeting(){
	double d, ha, va, s;
	int ret = CommandBase::targetingControl->vc->GetState(&ha, &va, &d, &s);
	if (ret == 0){
		screen->PrintfLine(DriverStationLCD::kUser_Line1, "HA:%3d, VA:%3d, D:%3d", (int) ha, (int) va, (int)d);
	}
	else{
		screen->PrintfLine(DriverStationLCD::kUser_Line1, "Nothing, ret = %d", ret);
	}
}


void OI::printCatapultSpeed(){
	double catapultspeed = getCatapultSpeed();
	screen->PrintfLine(DriverStationLCD::kUser_Line3, "Catapult Speed: %f2.2", catapultspeed);
}

void OI::UpdateScreen(){
	screen->UpdateLCD();
}
