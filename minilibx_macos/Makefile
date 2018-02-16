#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED := NO

all: $(NOM)

$(NOM):	$(OBJ)
	@printf "\n$(SILENT_COLOR)Compiling Mlx...$(NO_COLOR)"
	@ar rcs $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)\n"

%.o: %.c
	@if [ "$(HEADER_PRINTED)" = "NO" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)------------- MLX --------------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
		$(eval HEADER_PRINTED := YES) \
	fi
	@gcc $(CFLAGS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

%.o: %.m
	@gcc $(CFLAGS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@printf "$(SILENT_COLOR)mlx : Objects removed$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NOM)
	@printf "$(SILENT_COLOR)mlx : Library removed$(NO_COLOR)\n"

re: fclean all
