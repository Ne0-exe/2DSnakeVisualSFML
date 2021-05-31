#include "sXY.h"
#include <iostream>
#pragma once

class cSection {
protected:
	
	
public:
	int mXSize = 20;
	int mYSize = 20;
	sXY mCurrentPosition;
	cSection* mNextSection;
	cSection* mPreviousSection;
	cSection();
	virtual sXY getCurrentPosition();
	virtual int getDirection() { return(0); };
	virtual void Move() {};
};

