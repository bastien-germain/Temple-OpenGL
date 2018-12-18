#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
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
	/// The data need to be written following this format : <br>
	/// First character : describes the type of Section (CorridorSection = I, Left CornerSection = J, Right CornerSeciton = L, TSection = T) <br>
	/// Second character : describes the kind of Obstacle in the Section (None =  X, Simple Hole = h, Large Hole = H, Simple Barrier = b, Large Barrier = B, Simple Rock = r, Large Rock = R) <br>
	/// Third character : describes the position of the obstacle : value must be 1, 2 or 3 (does not matter if the Obstacle is a large one) <br>
	/// \param filePath : the path of the file that need to be read
	const std::vector<std::string> parse(const char * filePath) const;







};

#endif