#pragma once

#include "cSection.h"

#include <iostream>



class cHead : public cSection {
private:
	
	/*cSection* mN;
	cSection* mTemporary;
	cSection* mHead;*/
	
public:
	int mDirection; // 0-stoi w miejscu, 1- w prawo, 2-w dol, 3-w lewo, 4-w gore
	cHead();
	int getDirection();
	sXY getCurrentPosition()
	{
		return(mCurrentPosition);
	}
	void Move();
	void setDirection(int aDirection) {
		mDirection = aDirection;
	}
	void Grow();
};