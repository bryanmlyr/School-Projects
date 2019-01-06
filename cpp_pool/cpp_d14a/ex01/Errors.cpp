/*
** EPITECH PROJECT, 2018
** ex0
** File description:
** erros
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &msg, std::string const &comp) : _component(comp), _message(msg)
{}

std::string const &NasaError::getComponent() const
{
	return _component;
}

MissionCriticalError::MissionCriticalError(std::string const &msg, std::string const &comp) : NasaError(msg, comp)
{}

LifeCriticalError::LifeCriticalError(std::string const &msg, std::string const &comp) : NasaError(msg, comp)
{}

UserError::UserError(std::string const &msg, std::string const &comp) : NasaError(msg, comp)
{}

CommunicationError::CommunicationError(std::string const &msg, std::string const &comp) : NasaError(msg, comp)
{}