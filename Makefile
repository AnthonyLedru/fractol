# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 16:42:45 by aledru            #+#    #+#              #
#*   Updated: 2018/01/17 21:55:47 by aledru           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME := fractol

INCLUDE_FOLDERS := -I includes/ -I libft/includes/ -Iminilibx_macos/
SOURCES_FOLDER  := srcs/
OBJECTS_FOLDER  := objs/

vpath %.c srcs

FLAGS := -Wall -Wextra -Werror -Ofast
MLX	   := -framework OpenGL -framework AppKit
THREAD := -lpthread

SOURCES := \
		main.c \
		error.c \
		mlx.c \
		fractol.c \
		img.c \
		event_key.c \
		event_mouse.c \
		mandelbrot.c \
		julia.c \
		burningship.c \
		point.c \
		complex.c \
		color.c \
		params.c \



OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

all: header $(NAME)

header:
	@printf "\n$(HEAD_COLOR)--------------------------------\n"
	@printf "$(HEAD_COLOR)----------- Fractol ------------\n"
	@printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"

$(NAME): $(OBJECTS)
	@make -C libft/
	@make -C minilibx_macos/
	@printf "$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) -o $(NAME) $(OBJECTS) $(FLAGS) libft/libft.a $(MLX) $(THREAD) \
	minilibx_macos/libmlx.a
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)"

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)$(NAME) : Objects removed$(NO_COLOR)\n"

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx_macos clean
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)$(NAME) : Binary removed $(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re header
