/*
** EPITECH PROJECT, 2018
** Parser
** File description:
** ex00
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <string>
#include <stack>
#include <vector>

class Parser {
	public:
		Parser();
		virtual ~Parser();
		void feed(const std::string &);
		int result() const;
		void reset();
		void fillIt();
		void printNum();
		void printOp();
		void rotateNum();
		void tokenizer();
		void doCalc();
		int isSign(std::string size);
	private:
		std::string			_info;
		std::vector<std::string>	_tokens;
		std::stack<std::string>		_numbers;
		std::stack<std::string>		_operators;
		int				_res = 0;
};

#endif /* !PARSER_HPP_ */
