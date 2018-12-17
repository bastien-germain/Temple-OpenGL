#include "moteurJeu/Parser.hpp"

Parser::Parser() 
{
}

Parser::~Parser() 
{
}

void Parser::parse(const char * filePath) const 
{
	std::string line;

  	std::ifstream file(filePath);

  	if (file.is_open())
  	{
    	while (std::getline(file,line))
    	{
     	std::cout << line << std::endl;
   		}
    	file.close();
  	}

  	else THROW_EXCEPTION("FILE_OPENING_ERROR : Check file name");	
}