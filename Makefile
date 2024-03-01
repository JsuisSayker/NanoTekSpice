##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

SRC_MAIN	=	main.cpp

SRC 	=	Circuit.cpp								\
			loop.cpp								\
			$(DIR_COMPONENTS)

SRC_COMPONENTS	=	AComponent.cpp					\
					$(DIR_ELEM_COMPONENTS)			\
					$(DIR_SRC_SPECIALS_COMPONENTS)	\
					$(DIR_GATE_COMPONENTS)

SRC_PARSER	=	Parser.cpp			\
				ComponentFactory.cpp

SRC_GATE_COMPONENTS	=	Gate4071Component.cpp	\
						Gate4001Component.cpp	\
						Gate4081Component.cpp	\
						Gate4011Component.cpp	\
						Gate4030Component.cpp

SRC_ELEMENTARY_COMPONENTS	=	AndComponent.cpp	\
								NotComponent.cpp	\
								OrComponent.cpp		\
								XorComponent.cpp

SRC_SPECIALS_COMPONENTS	=	TrueComponent.cpp		\
							FalseComponent.cpp		\
							InputComponent.cpp		\
							OutputComponent.cpp		\
							ClockComponent.cpp		\


DIR_MAIN = $(addprefix src/, $(SRC_MAIN))

DIR_SRC = $(addprefix src/, $(SRC))

DIR_PARSER = $(addprefix src/Parser/, $(SRC_PARSER))

DIR_COMPONENTS = $(addprefix Components/, $(SRC_COMPONENTS))

DIR_ELEM_COMPONENTS	=\
	$(addprefix ElementaryComponents/, $(SRC_ELEMENTARY_COMPONENTS))

DIR_SRC_SPECIALS_COMPONENTS	=\
	$(addprefix SpecialComponents/, $(SRC_SPECIALS_COMPONENTS))

DIR_GATE_COMPONENTS	=\
	$(addprefix GatesComponents/, $(SRC_GATE_COMPONENTS))

OBJ_MAIN		=	$(DIR_MAIN:.cpp=.o)

OBJ_SRC			=	$(DIR_SRC:.cpp=.o)

OBJ_PARSER		=	$(DIR_PARSER:.cpp=.o)

OBJ				=	$(OBJ_MAIN) $(OBJ_SRC) $(OBJ_PARSER)

NAME			=	nanotekspice

CFLAGS			=	-std=c++20 -Wall -Wextra

CPPFLAGS		=	-I./include/Components -I./include -I./include/Parser

all:	$(NAME)

debug:
	g++ -o $(NAME) $(DIR_MAIN) $(DIR_SRC) $(DIR_PARSER) -ggdb3 $(CPPFLAGS) \
$(CFLAGS)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) vgcore* *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -rf unit_tests

re:	fclean all

.PHONY: clean fclean re tests_run
