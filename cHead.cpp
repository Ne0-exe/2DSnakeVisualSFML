#include "cHead.h"
#include "cBody.h"

cHead::cHead()
{
	
}

int cHead::getDirection() {
	return(mDirection);
}

void cHead::Grow() {

	cSection* wsk = this;

	while (wsk->mNextSection != nullptr) {
		wsk = wsk->mNextSection;
	}

	int direction = wsk->getDirection();
	sXY newSectionPosition = wsk->getCurrentPosition();
	if (direction == 1) {
		newSectionPosition.x = mCurrentPosition.x - mXSize; // w prawo 
	}
	else if (direction == 2) {
		newSectionPosition.y = mCurrentPosition.y - mYSize; // w dol 
	}
	else if (direction == 3) {
		newSectionPosition.x = mCurrentPosition.x + mXSize; // w lewo 
	}
	else if (direction == 4) {
		newSectionPosition.y = mCurrentPosition.y + mYSize; // w gore 
		
	}
	else if (direction == 5) {
		newSectionPosition.y = mCurrentPosition.y + mYSize; // w gore po prawo
		newSectionPosition.x = mCurrentPosition.x;
	}
	else {
		newSectionPosition.y = mCurrentPosition.y;
		newSectionPosition.x = mCurrentPosition.x;
	}



	cSection* newSection = new cBody(newSectionPosition);
	wsk->mNextSection = newSection;
	newSection->mPreviousSection = wsk;

}
void cHead::Move()
{
	if (mDirection == 1) {
		mCurrentPosition.x++; // w prawo
	}
	else if (mDirection == 2) {
		mCurrentPosition.y++; // w dol
	}
	else if (mDirection == 3) {
		mCurrentPosition.x--; // w lewo
	}
	else if (mDirection == 4) {
		mCurrentPosition.y--; // w gore
	}
	else if (mDirection == 5) {
		mCurrentPosition.y--; // w gore po prawo
	}

	cSection* wsk = this;

	while (wsk->mNextSection != nullptr) {
		wsk = wsk->mNextSection;
		wsk->Move();
	}
}