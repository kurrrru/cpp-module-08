NAME = span

# sources
SRCS = main.cpp \
	Span.cpp \
	SpanException.cpp \
	../toolbox/color.cpp \
	../toolbox/StepMark.cpp

OBJS = $(SRCS:.cpp=.o)

# compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I..

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean-log:
	$(RM) *.log

re: fclean all

.PHONY: all clean fclean re clean-log
