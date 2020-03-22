SRC1		=	$(wildcard src/*.cpp ./*.cpp) 

OBJ1		=	$(SRC1:%.cpp=%.o)

NAME1		=	game

CXX			=	g++
CXXFLAGS	=	-I./include -Wall -pedantic -Wextra -Werror -std=c++17 -g
LIBFLAGS	=	-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

RM			=	rm -f

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
			$(CXX) $(OBJ1) -o $(NAME1) $(CXXFLAGS) $(LIBFLAGS)
clean:
	$(RM)	$(OBJ1) 

fclean:		clean
			$(RM) $(NAME1) 

re:			fclean all

coffee:		fclean all clean

.PHONY:		all clean fclean re