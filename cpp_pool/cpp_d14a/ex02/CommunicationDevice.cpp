
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    : _api(input, output)
{
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    	for (size_t i = 0; i < nbUsers; ++i)
		_api.addUser(users[i]);

	try {
    		_api.startMission(missionName);
	} catch (std::logic_error const &err) {
		std::cerr << "LogicError: " << err.what() << std::endl;
	} catch (std::runtime_error const &err) {
		std::cerr << "RuntimeError: " << err.what() << std::endl;
	} catch (std::exception const &err) {
		std::cerr << "Error: " << err.what() << std::endl;
	}
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
	try {
    		_api.sendMessage(user, message);
	} catch (std::exception const &err) {
		std::cerr << err.what() << std::endl;
	}
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
	try {
    		_api.receiveMessage(user, message);
	} catch (std::exception const &err) {
		std::cerr << "INVALID MESSAGE" << std::endl;
	}
}
