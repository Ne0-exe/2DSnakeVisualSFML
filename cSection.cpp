#include "cSection.h"

cSection::cSection()
{
	std::cout << "cSection\n";
	mCurrentPosition.x = 500;
	mCurrentPosition.y = 300;
	mNextSection = nullptr;
	mPreviousSection = nullptr;
}
sXY cSection::getCurrentPosition() {
	return(mCurrentPosition);
}