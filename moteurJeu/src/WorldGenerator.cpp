#include "moteurJeu/WorldGenerator.hpp"

WorldGenerator::WorldGenerator(const FilePath &applicationPath) : 
	_offsetPosZCount(0), _lastRotateIndex(0), 
	_rotateIndicator(0), _lastCornerRight(false), 
	_penultimateCornerRight(false), _popCounter(0), 
	_sectionDataFilePath(applicationPath.dirPath() + "assets/sectionsData/sectionsData.txt")
{
}

WorldGenerator::~WorldGenerator()
{
}

std::string WorldGenerator::generateSectionData() const
{
	std::string type;
	std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(-1, 1);

    switch (dis(gen))
    {
    	case -1:
    		type = "J";
    		break;
    	case 0:
    		type = "I";
    		break;
    	case 1:
    		type = "L";
    		break;
    	default:
    		break;
    }

    return type + "X2";
}

void WorldGenerator::generateInitialSections(PositionObserver *observer, const Factory &factory)
{	
	bool noCorner = true;
	unsigned int counter = 0;

	_sectionVec.push_back(factory.create("IX2", observer));
	_sectionVec.push_back(factory.create("IX2", observer));

	for (int i = 0; i < SECTIONS_NUMBER - 3; ++i)
	{
		_sectionVec.push_back(factory.create(generateSectionData(), observer));
	}
	_sectionVec.push_back(factory.create("LX2", observer));
	
	while (noCorner)
	{		
		_sectionVec[counter].setZ(_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z);
		_sectionVec[counter].setX(_sectionVec[_lastRotateIndex].posZ());

		if (_sectionVec[counter].isCorner())
		{	
			noCorner = false;
			_rotateIndicator = _sectionVec[counter].cornerDirection();

			if (_rotateIndicator == 1)
				_lastCornerRight = _penultimateCornerRight = true;
			
		}
		_offsetPosZCount++;
		counter++;
	}

	_lastRotateIndex = counter - 1 ;
	_offsetPosZCount = 0;

	for (int i = counter; i < SECTIONS_NUMBER; ++i)
	{
		placeSection(i);
	}
	
}

void WorldGenerator::generateSection(PositionObserver *observer, const Factory &factory)
{
	_sectionVec.push_back(factory.create(generateSectionData(), observer));
	placeSection(_sectionVec.size());
}

void WorldGenerator::generateSectionsFromFile(PositionObserver *observer, const Factory &factory, const Parser &parser) 
{	
	std::vector<std::string> data = parser.parse(_sectionDataFilePath);
	bool noCorner = true;
	unsigned int counter = 0;

	while (noCorner && counter < data.size())
	{		
		_sectionVec.push_back(factory.create(data[counter], observer));

		_sectionVec[counter].setZ(_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z);
		_sectionVec[counter].setX(_sectionVec[_lastRotateIndex].posZ());

		if (_sectionVec[counter].isCorner())
		{	
			noCorner = false;
			_rotateIndicator = _sectionVec[counter].cornerDirection();

			if (_rotateIndicator == 1)
				_lastCornerRight = _penultimateCornerRight = true;
			
		}
		_offsetPosZCount++;
		counter++;
	}

	_lastRotateIndex = counter - 1 ;
	_offsetPosZCount = 0;

	for(unsigned int i = counter; i < data.size(); ++i)
	{
		_sectionVec.push_back(factory.create(data[i], observer));
		placeSection(i);
	}


}
void WorldGenerator::placeSection(const unsigned int i)
{
	if (_rotateIndicator == 0) 
	{
		if (_penultimateCornerRight && !_lastCornerRight)
		{
			_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() - SECTION_WIDTH - CORRIDOR_WIDTH + _offsetPosZCount * POSITION_OFFSET_Z );
			_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() + SECTION_WIDTH);
		}
		if (_penultimateCornerRight && _lastCornerRight)
		{
			_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() - _offsetPosZCount * POSITION_OFFSET_Z + SECTION_WIDTH + CORRIDOR_WIDTH);
			_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() - SECTION_WIDTH);
		}
		if (!_penultimateCornerRight && !_lastCornerRight)
		{
			_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
			_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() + SECTION_WIDTH);
		}
		if (!_penultimateCornerRight && _lastCornerRight)
		{
			_sectionVec[i].setZ(-_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
			_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() - SECTION_WIDTH );
		}
	}
	else
	{
		if (_rotateIndicator > 0)
		{	
			if (_penultimateCornerRight && !_lastCornerRight)
			{
				_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() + (_offsetPosZCount + 1 ) * POSITION_OFFSET_Z + SECTION_WIDTH);
				_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() + SECTION_WIDTH);
			}
			if (_penultimateCornerRight && _lastCornerRight)
			{
				_sectionVec[i].setZ(- _sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
				_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() - SECTION_WIDTH);
			}
			if (!_penultimateCornerRight && _lastCornerRight)
			{
				_sectionVec[i].setZ(- _sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
				_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() + POSITION_OFFSET_Z + SECTION_WIDTH + CORRIDOR_WIDTH);
			}
			if (!_penultimateCornerRight && !_lastCornerRight)
			{
				_sectionVec[i].setZ(- _sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
				_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() + POSITION_OFFSET_Z + SECTION_WIDTH + CORRIDOR_WIDTH);
			}
		}
		else
		{	
			if (!_penultimateCornerRight && !_lastCornerRight)
			{	
				_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() + (_offsetPosZCount + 1) * POSITION_OFFSET_Z + SECTION_WIDTH);
				_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() + SECTION_WIDTH);
			}
			if (_penultimateCornerRight && !_lastCornerRight)
			{
				_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
				_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() + SECTION_WIDTH);
			}
			if (_penultimateCornerRight && _lastCornerRight)
			{
				_sectionVec[i].setZ(_sectionVec[_lastRotateIndex].posX() - (_offsetPosZCount + 1) * POSITION_OFFSET_Z - SECTION_WIDTH);
				_sectionVec[i].setX(-_sectionVec[_lastRotateIndex].posZ() - POSITION_OFFSET_Z - SECTION_WIDTH);
			}
			if (!_penultimateCornerRight && _lastCornerRight)
			{
				_sectionVec[i].setZ(-_sectionVec[_lastRotateIndex].posX() + _offsetPosZCount * POSITION_OFFSET_Z - SECTION_WIDTH - CORRIDOR_WIDTH);
				_sectionVec[i].setX(_sectionVec[_lastRotateIndex].posZ() + POSITION_OFFSET_Z + SECTION_WIDTH + CORRIDOR_WIDTH);
			}
		}
	}
	if (!_sectionVec[i].isCorner()) 
		_offsetPosZCount++;
	else 
	{	
		_lastRotateIndex = i;
		_offsetPosZCount = 0;
		_penultimateCornerRight = _lastCornerRight;

		if (_sectionVec[i].cornerDirection() == 1)
			_lastCornerRight = true;
		else 
			_lastCornerRight = false;

		_rotateIndicator = (_rotateIndicator + _sectionVec[i].cornerDirection()) %4;
    }
}