#include "moteurJeu/Parser.hpp"

Parser::Parser() 
{
}

Parser::~Parser() 
{
}

std::vector<std::string> Parser::parse(const std::string &filePath) const 
{
  std::vector<std::string> out;
  std::string line;

  std::ifstream file(filePath);

    if (file.is_open())
    {
      while (std::getline(file,line))
      {
        out.push_back(line);
  
      }
      file.close();
      return out;
    }

    else THROW_EXCEPTION("FILE_OPENING_ERROR : Check file name"); 
  
}