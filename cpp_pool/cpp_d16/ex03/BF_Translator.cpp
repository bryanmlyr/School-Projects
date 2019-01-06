/*
** EPITECH PROJECT, 2018
** BrainFuck
** File description:
** Translate
*/

#include "BF_Translator.hpp"
#include <fstream>
#include <map>
#include <iostream>

BF_Translator::BF_Translator()
{}

BF_Translator::~BF_Translator()
{}

int	BF_Translator::translate(const std::string &in, const std::string &out)
{
	std::map<std::string, std::string> instructions;
	instructions.insert(std::pair<std::string, std::string>("init", "#include <stdlib.h>\n#include <stdio.h>\nint main()\n{\nchar *array = calloc(61440, sizeof(char));\n"));
	instructions.insert(std::pair<std::string, std::string>("close", "return 0;\n}\n"));
	instructions.insert(std::pair<std::string, std::string>("+", "++*array;\n"));
	instructions.insert(std::pair<std::string, std::string>("-", "--*array;\n"));
	instructions.insert(std::pair<std::string, std::string>(">", "++array;\n"));
	instructions.insert(std::pair<std::string, std::string>("<", "--array;\n"));
	instructions.insert(std::pair<std::string, std::string>(".", "putchar(*array);\n"));
	instructions.insert(std::pair<std::string, std::string>(",", "*array=getchar();\n"));
	instructions.insert(std::pair<std::string, std::string>("[", "while (*array) {\n"));
	instructions.insert(std::pair<std::string, std::string>("]", "}\n"));
	std::fstream brainFuckFile(in, std::fstream::in);
	if (!brainFuckFile.is_open())
		return -1;
	std::fstream cFile(out, std::fstream::out | std::fstream::trunc);
	std::string brainFuckData;
	std::string temp;

	if (!cFile.is_open())
		return -1;
	getline(brainFuckFile, brainFuckData, '\0');
	cFile << instructions["init"];
	for (unsigned int x = 0; x < brainFuckData.size(); x++) {
		temp += brainFuckData[x];
		cFile << instructions[temp];
		temp = "";
	}
	cFile << instructions["close"];
	return 0;
}