/*
** EPITECH PROJECT, 2018
** Container
** File description:
** Ex04
*/

#ifndef CONTAINER_HPP_
	#define CONTAINER_HPP_

#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>


template<typename T, template <typename, typename> class Container>
class contain {
	public:
		void push(T elem)
		{
			_container.push_back(elem);
		}
		void aff(T b) const
		{
			std::cout << "Value:\t" << b << std::endl;
		}
		void add(T &b)
		{
			b += 1;
		}
		void aff() const
		{
			for (auto &elem : _container)
				aff(elem);
		}
		void add()
		{
			for (auto &elem : _container)
				add(elem);
		}
	private:
		Container<T, std::allocator<T>> _container;
};

#endif /* !CONTAINER_HPP_ */
