#include "BasicDrive.h"

BasicDrive::BasicDrive()
{}

void BasicDrive::begin(Collection<int> leftMotorPins, Collection<int> leftEncoderPins, Collection<int> rightMotorPins, Collection<int> rightEncoderPins)
{
	int leftEncA = leftEncoderPins.get(0);
	int leftEncB = leftEncoderPins.get(1);
	
	int rightEncA = rightEncoderPins.get(0);
	int rightEncB = rightEncoderPins.get(1);
	
	int leftMotA = leftMotorPins.get(0);
	int leftMotB = leftMotorPins.get(1);
	int leftMotEnb = leftMotorPins.get(2);
	
	int rightMotA = rightMotorPins.get(0);
	int rightMotB = rightMotorPins.get(1);
	int rightMotEnb = rightMotorPins.get(2);
	
	Motor left;
	left.begin(leftMotA, leftMotB, leftMotEnb);
	
	Motor right;
	right.begin(rightMotA, rightMotB, rightMotEnb);
	
	Encoder rightEnc(rightEncA, rightEncB);
	this->rightEncoder = rightEnc;
	
	Encoder leftEnc(leftEncA, leftEncB);
	this->leftEncoder = leftEnc;
	
	//Left = A 
	//Right = B
	MotorController controller;
	controller.begin(left, right);
	this->motorController = controller;
}

void BasicDrive::begin(Motor& leftMot, Motor& rightMot, Encoder& leftEnc, Encoder& rightEnc)
{
	MotorController controller;
	controller.begin(leftMot, rightMot);

	this->motorController = controller;
	
	this->leftEncoder = leftEnc;
	
	this->rightEncoder = rightEnc;
}

void BasicDrive::setOutput(float leftOut, float rightOut)
{
	motorController.outputMotorA(leftOut);
	
	motorController.outputMotorB(rightOut);
}

Encoder& BasicDrive::getLeftEncoder()
{
	return this->leftEncoder;
}

Encoder& BasicDrive::getRightEncoder()
{
	return this->rightEncoder;
}

void BasicDrive::resetEncoders()
{
	leftEncoder.reset();
	rightEncoder.reset();
}