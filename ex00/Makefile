NAME = btc

SRC_DIR = src/

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++11


RM = rm -f

SRCS =		$(SRC_DIR)main.cpp \



OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
