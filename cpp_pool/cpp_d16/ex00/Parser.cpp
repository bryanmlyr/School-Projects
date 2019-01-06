/*
** EPITECH PROJECT, 2018
** parser
** File description:
** template
*/

#include "Parser.hpp"
#include <string>
#include <iostream>
#include <vector>

Parser::Parser()
{}

Parser::~Parser()
{}

void	Parser::feed(const std::string &info)
{
	std::string temp = "(";

	_info = info;
	temp += _info;
	_info = temp;
	_info += ")";
	fillIt();
}

void	Parser::reset()
{
	_tokens.clear();
	while (!_numbers.empty()) {
		_numbers.pop();
	}
	while (!_operators.empty()) {
		_operators.pop();
	}
	_res = 0;
}

void	Parser::printNum()
{
	std::stack<std::string> temp = _numbers;

	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
}

void	Parser::printOp()
{
	std::stack<std::string> temp = _operators;

	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
}

void	Parser::rotateNum()
{
	std::stack<std::string> temp = _numbers;
	std::stack<std::string> fin;
	std::vector<std::string> rotator;

	while (!temp.empty())
	{
		rotator.push_back(temp.top());
		temp.pop();
	}
	for (unsigned int x = 0; x < rotator.size(); x++) {
		fin.push(rotator[x]);
	}
	_numbers = fin;
}

void	Parser::tokenizer()
{
	std::string 	temp = "";
	int		x = 0;

	while (_info[x]) {
		while (_info[x] >= '0' && _info[x] <= '9' && _info[x]) {
			temp += _info[x++];
		}
		if (temp != "") {
			_tokens.push_back(temp);
			temp = "";
		}
		if (_info[x] < '0' || _info[x] > '9') {
			temp = _info[x];
			_tokens.push_back(temp);
			temp = "";
			x++;
		}
	}
}

int	Parser::isSign(std::string str)
{
	if (str == "+" || str == "-")
		return 1;
	if (str == "%" || str == "*" || str == "/")
		return 2;
	return 0;
}

void	Parser::fillIt()
{
	unsigned	int x = 0;
	std::string	temp = "";

	for (x = 0; x < _info.size(); x++) {
		while (_info[x] == ' ' && x < _info.size())
			_info.erase(_info.begin() + x);
	}
	x = 0;
	tokenizer();
	while (x < _tokens.size()) {
		temp = _tokens[x];
		if (temp == "(") {
			_operators.push(temp);
			x++;
      		}
      		else if (temp == ")") {
         		while (!_operators.empty() && _operators.top() != "(") {
				_numbers.push(_operators.top());
            			_operators.pop();
         		}
         		if (!_operators.empty())
            			_operators.pop();
         		x++;
      		}
		if (temp != "(" && temp != ")") {
			if (isSign(temp) == 0) {
				_numbers.push(temp);
      			} else {
         			if (_operators.empty()) {
            				_operators.push(temp);
         			} else {
            				while (!_operators.empty() && _operators.top() != "(" && isSign(temp) <= isSign(_operators.top())) {
						_numbers.push(_operators.top());
               					_operators.pop();
            				}
            				_operators.push(temp);
         			}
      			}
      			x++;
		}
   	}
   	while (!_operators.empty()) {
		_numbers.push(_operators.top());
      		_operators.pop();
   	}
	rotateNum();
	//printNum();
	doCalc();
}

void	Parser::doCalc()
{
	std::stack<std::string>		calc;
	std::string			temp, a, b;
	int				last = 0;

	while (!_numbers.empty()) {
		if (isSign(_numbers.top()) == 0)
			calc.push(_numbers.top());
		else {
			temp = _numbers.top();
			if (temp == "*") {
				a = calc.top();
				calc.pop();
				b = calc.top();
				calc.pop();
				//std::cout << stoi(b) << " * " << stoi(a) << std::endl;
				last = stoi(b) * stoi(a);
				//std::cout << last << std::endl;
				calc.push(std::to_string((stoi(b) * stoi(a))));
			} else if (temp == "/") {
				a = calc.top();
				calc.pop();
				b = calc.top();
				calc.pop();
				//std::cout << stoi(b) << " / " << stoi(a) << std::endl;
				last = stoi(b) / stoi(a);
				//std::cout << last << std::endl;
				calc.push(std::to_string((stoi(b) / stoi(a))));
			} else if (temp == "%") {
				a = calc.top();
				calc.pop();
				b = calc.top();
				calc.pop();
				//std::cout << stoi(b) << " % " << stoi(a) << std::endl;
				last = stoi(b) % stoi(a);
				//std::cout << last << std::endl;
				calc.push(std::to_string((stoi(b) % stoi(a))));
			} else if (temp == "+") {
				a = calc.top();
				calc.pop();
				b = calc.top();
				calc.pop();
				//std::cout << stoi(b) << " + " << stoi(a) << std::endl;
				last = stoi(b) + stoi(a);
				//std::cout << last << std::endl;
				calc.push(std::to_string((stoi(b) + stoi(a))));
			} else if (temp == "-") {
				a = calc.top();
				calc.pop();
				b = calc.top();
				calc.pop();
				//std::cout << stoi(b) << " - " << stoi(a) << std::endl;
				last = stoi(b) - stoi(a);
				//std::cout << last << std::endl;
				calc.push(std::to_string((stoi(b) - stoi(a))));
			}
		}
		_numbers.pop();
	}
	_res += last;
}

int	Parser::result() const
{
	return _res;
}