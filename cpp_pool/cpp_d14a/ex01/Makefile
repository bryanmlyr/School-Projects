SRC =		Errors.cpp			\
		AtmosphereRegulator.cpp		\
		Engine.cpp			\
		Oxygenator.cpp			\
		RoverUnitTests.cpp		\
		WaterReclaimer.cpp

CXX = g++
CXXFLAGS = -W -Wall -Wextra -std=c++11
LDFLAGS =
NAME = ex01

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:	all
	./$(NAME)
