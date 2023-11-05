# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 15:16:24 by bsavinel          #+#    #+#              #
#    Updated: 2023/11/05 16:46:46 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Logger

################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
CPPFLAGS		= -MMD

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	main.cpp		\


################################################################################
#                               INCLUDES                             	       #
################################################################################

INCS			=	
					
LIB				=	

################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

SRC_PATH		=	./
OBJ_PATH		=	./objs/

################################################################################
#                               OUTPUT_FILES                              	   #
################################################################################

OBJS			=	$(addprefix $(OBJ_PATH), ${SRCS:.cpp=.o})
DEPS			=	${OBJS:.o=.d}

################################################################################
#                                   COLORS                                     #
################################################################################

RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
NO_COLOR		=	\033[m

################################################################################
#                                   RULES                                      #
################################################################################

all	: 
	echo "$(CYAN)"Compilation of $(NAME) in progress... "$(NO_COLOR)"
	make $(NAME) --no-print-directory && echo "$(GREEN)"$(NAME) -- Compilation complete ! "$(NO_COLOR)" || echo "$(RED)"$(NAME) -- Compilation Failed "$(NO_COLOR)"

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(INCS)

$(OBJ_PATH)%.o : $(SRC_PATH)%.cpp
	mkdir -p $(dir $@)
	echo "$(YELLOW)""Compiling $<""$(NO_COLOR)"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCS) -c $< -o $@  

clean :
	echo "$(PURPLE)""Cleaning objects and dependence files""$(NO_COLOR)"
	rm -rf $(OBJ_PATH)

fclean : clean
	echo "$(PURPLE)""Cleaning executable""$(NO_COLOR)"
	rm -rf $(NAME)

re : fclean 
	$(MAKE) all --no-print-directory

bonus : all

-include $(DEPS)

.PHONY : all clean fclean re

.SILENT :