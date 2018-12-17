#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <fstream> 
#include <string>
#include <moteurJeu/Exception.hpp>

/// \class Parser
/// \brief Class defining a Parser
///  - The Parser parses data - from an external file, written in a special format - to data specific to the game;
class Parser 
{

private:

public:
	/// \brief Default constructor
	Parser();

	/// \brief Destructor
	~Parser();

	/// \brief Parses a file to data
	/// \param filePath : the path of the file that need to be read
	void parse(const char * filePath) const;







};

#endif