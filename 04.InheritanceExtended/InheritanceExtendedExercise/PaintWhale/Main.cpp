#include <iostream>

class Size
{
public:
	double x;
	double y;
};

class PaintObject
{
public:
	unsigned char color[4];
	Size size;
	Size sheetSize;
	unsigned char backgroundColor[4];
};

class Whale
{
public:
	Size size;
	unsigned char skinColor[4];
	unsigned short mass;
};

class PaintWhale : public PaintObject, public Whale
{
public:
	PaintWhale()
	{
	}

	void calculateWhaleSizeOnSheet();
	double getScaleFactor();
};

void PaintWhale::calculateWhaleSizeOnSheet()
{
	double scaleFactorOnX = this->Whale::size.x / this->PaintObject::sheetSize.x;
	double scaleFactorOnY = this->Whale::size.y / this->PaintObject::sheetSize.y;
	double desiredScaleFactor;
	if (scaleFactorOnX > scaleFactorOnY)
	{
		desiredScaleFactor = scaleFactorOnX;
	}
	else
	{
		desiredScaleFactor = scaleFactorOnY;
	}

	this->PaintObject::size.x = this->Whale::size.x / desiredScaleFactor;
	this->PaintObject::size.y = this->Whale::size.y / desiredScaleFactor;
}

double PaintWhale::getScaleFactor()
{
	return this->PaintObject::size.x / this->Whale::size.x;
}

int main()
{
	PaintWhale paintWhale;
	paintWhale.Whale::size.x = 12;
	paintWhale.Whale::size.y = 4;
	paintWhale.PaintObject::sheetSize.x = 0.3;
	paintWhale.PaintObject::sheetSize.y = 0.3;
	paintWhale.calculateWhaleSizeOnSheet();
	std::cout << "Scale factor: " << paintWhale.getScaleFactor() << std::endl;

	return 0;
}