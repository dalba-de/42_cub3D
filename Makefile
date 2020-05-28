# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 13:38:39 by dalba-de          #+#    #+#              #
#    Updated: 2020/05/28 13:31:28 by dalba-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# This is a minimal set color codes
_END		=	\033[0m
_BOLD		=	\033[1m
_UNDER		=	\033[4m
_REV		=	\033[7m

# Colors
_GREY		=	\033[30m
_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_BLUE		=	\033[34m
_PURPLE		=	\033[35m
_CYAN		=	\033[36m
_WHITE		=	\033[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\033[40m
_IRED		=	\033[41m
_IGREEN		=	\033[42m
_IYELLOW	=	\033[43m
_IBLUE		=	\033[44m
_IPURPLE	=	\033[45m
_ICYAN		=	\033[46m
_IWHITE		=	\033[47m

# **************************************************************************** #

NAME = cub3D

NAME_B = cub3D_bonus

CC = @gcc

CFLAGS = -I./includes -Wall -Werror -Wextra -g

BCFLAGS = -I./bonus/includes -Wall -Werror -Wextra -g

LXFLAGS = -Lmlx -lmlx -no-pie -lXext -lX11 -lbsd -lm #-framework OpenGL -framework AppKit

SRC_DIR = ./

SRC_B_DIR = bonus/

INC_DIR = includes/

OBJ_DIR = objects/

OBJ_B_DIR = bonus/objects/

SRC =	main.c exit.c check.c get_next_line.c key.c key_move.c raycasting.c color.c drawing.c sprite.c first_lecture.c bitmap.c map_error.c \
		tools/ft_putstr.c tools/ft_putchar.c tools/ft_strcmp.c tools/ft_strlen.c  tools/ft_substr.c tools/ft_strjoin.c \
		tools/ft_strdup.c tools/ft_strchr.c tools/ft_isdigit.c tools/ft_atoi.c tools/ft_memcpy.c tools/ft_bzero.c \
		parser/parser.c parser/fill_flags.c parser/fill_map.c parser/init_map.c \

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.c=.o})

SRC_B =	main_bonus.c exit_bonus.c check_bonus.c get_next_line_bonus.c key_bonus.c key_move_bonus.c map_error_bonus.c \
		minimap_bonus.c raycasting_bonus.c color_bonus.c drawing_bonus.c sprite_bonus.c first_lecture_bonus.c \
		bitmap_bonus.c floor_and_ceiling_bonus.c door_bonus.c quest_bonus.c textures_bonus.c weapon_bonus.c \
		hud_bonus.c textures2_bonus.c enemy_bonus.c sprite_drawing_bonus.c hud_2_bonus.c pick_bonus.c \
		drawing_select_text.c \
		tools/ft_putstr.c tools/ft_putchar.c tools/ft_strcmp.c tools/ft_strlen.c  tools/ft_substr.c tools/ft_strjoin.c \
		tools/ft_strdup.c tools/ft_strchr.c tools/ft_isdigit.c tools/ft_atoi.c tools/ft_memcpy.c tools/ft_bzero.c \
		parser/parser_bonus.c parser/fill_flags_bonus.c parser/fill_map_bonus.c parser/init_map_bonus.c \

OBJ_B = $(addprefix ${OBJ_B_DIR}, ${SRC_B:.c=.o})

all:	${NAME}

${NAME}:		${OBJ}
			@echo "$(_CYAN) All files compiled. $(_END)✅"
			${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${LXFLAGS}
			@echo "$(_CYAN) Executable $(_BOLD)$(_CYAN)'$(NAME)'$(_END)$(_CYAN) compiled. $(_END)✅"

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p objects/tools/
	@mkdir -p objects/parser/
	${CC} ${CFLAGS} -o $@ -c $<

bonus:	${NAME_B}

${NAME_B}:		${OBJ_B}
			@echo "$(_CYAN) All files compiled. $(_END)✅"
			${CC} ${BCFLAGS} ${OBJ_B} -o ${NAME_B} ${LXFLAGS}
			@echo "$(_CYAN) Executable $(_BOLD)$(_CYAN)'$(NAME)'$(_END)$(_CYAN) compiled. $(_END)✅"

${OBJ_B_DIR}%.o: ${SRC_B_DIR}%.c
	@mkdir -p bonus/objects/tools/
	@mkdir -p bonus/objects/parser/
	${CC} ${BCFLAGS} -o $@ -c $<

clean:
		@rm -f ${OBJ}
		@rm -rf ${OBJ_DIR}
		@rm -f ${OBJ_B}
		@rm -rf ${OBJ_B_DIR}
		@echo "$(_RED)$(_BOLD)'"$(OBJ_DIR)"'$(_END)$(_RED)has been deleted. $(_END)🗑️"

fclean:	clean
		@rm -f ${NAME}
		@rm -f ${NAME_B}
		@rm -f screenshot.bmp
		@echo "$(_RED)$(_BOLD)'"$(NAME)"'$(_END)$(_RED) and $(_BOLD)'"Screenshot"'$(_END)$(_RED) has been deleted. $(_END)🗑️"

re: fclean all

reb: fclean bonus

.PHONY:	clean fclean all re	
