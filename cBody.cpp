#include "cBody.h"
#include "cSection.h"
#include "cHead.h"
#include <iostream>

using namespace std;

cBody::cBody(sXY aCurrentPosition)
{
	mCurrentPosition = aCurrentPosition;
}

sXY cBody::getCurrentPosition(){
	return(mCurrentPosition);
}
int cBody::getDirection() {
	int direction;

	sXY previousModulePosition = mPreviousSection->getCurrentPosition();
	
	int xChange = previousModulePosition.x - mCurrentPosition.x;
	int yChange = previousModulePosition.y - mCurrentPosition.y;
	// 0-stoi w miejscu, 1- w prawo, 2-w dol, 3-w lewo, 4-w gore
	if (xChange > 0) {
		direction = 1; // w prawo
	
	}
	else if (yChange > 0) {
		direction = 2;  // w dol
	
	}
	else if (xChange < 0) {
		direction = 3;  // w lewo
	
	}
	else if (yChange < 0) {
		direction = 4;  // w gore
	} 
	else if (yChange == 0) {
		direction = 5;  // w gore
	}
	else {
		direction = 0;
	}
	std::cout << "KIERUNEK (1-4): " << direction << "\n";
	std::cout << "POZYCJA GLOWY X: " << previousModulePosition.x << "\n";
	std::cout << "POZYCJA GLOWY Y: " << previousModulePosition.y << "\n";
	std::cout << "POZYCJA CIALKA X: " << mCurrentPosition.x << "\n";
	std::cout << "POZYCJA CIALKA Y: "<< mCurrentPosition.y << "\n";

	return(direction);
	
}
void cBody::Move()
{
	sXY previousSectionPosition = mPreviousSection->getCurrentPosition();
	int direct = getDirection();

	std::cout << direct << "\n";
	if (direct == 1) {
		mCurrentPosition.x = previousSectionPosition.x - mXSize; // w prawo
		mCurrentPosition.y = previousSectionPosition.y;
		cout << "IDE SOBIE W PRAWO\n";
	}
	else if (direct == 2) {
		mCurrentPosition.y = previousSectionPosition.y - mYSize; // w dol
		mCurrentPosition.x = previousSectionPosition.x;
		cout << "IDE SOBIE W DOL\n";
	}
	else if (direct == 3) {
		mCurrentPosition.x = previousSectionPosition.x + mXSize; // w lewo
		mCurrentPosition.y = previousSectionPosition.y;
		cout << "IDE SOBIE W LEWO\n";
	}
	else if (direct == 4) {
		mCurrentPosition.y = previousSectionPosition.y + mYSize; // w gore
		mCurrentPosition.x = previousSectionPosition.x;
	}
	else if (direct == 5) {
		mCurrentPosition.y = previousSectionPosition.y + mYSize; // w gore po prawo
		mCurrentPosition.x = previousSectionPosition.x;
	}
}
	//std::cout << "Body";
	//std::cout << mCurrentPosition.x << "\n";


