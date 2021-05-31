#pragma once
#include "cSection.h"


class cBody : public cSection {
protected:
	sXY NextPosition;
	
public:
	cBody(sXY aCurrentPosition);
	void Move();
	sXY getCurrentPosition();
	int getDirection();
};
