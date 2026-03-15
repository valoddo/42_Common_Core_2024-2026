# Nome della libreria statica 
NAME = miniRT

BONUS_NAME = miniRT_bonus

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directory minilibx (nella root del progetto)
MINI = minilibx-linux
MINILIBX_URL = https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.tar.gz

# Nome della libreria minilibx
MINILIBX = $(MINI)/libmlx_Linux.a

# Flag per il linking
LDFLAGS = -L$(MINI) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

# Libreria get_next_line
GET = get_next_line
GET_LIB = $(GET)/get_next_line.a

# Regola per compilare tutto
all: $(MINILIBX) $(GET_LIB) $(NAME) 

bonus: $(MINILIBX) $(GET_LIB) $(BONUS_NAME) 

# Lista dei filename sorgenti e oggetti
SRCS = mandatory/colors.c mandatory/rays.c mandatory/camera.c mandatory/vector_math.c mandatory/vector_operations.c mandatory/vectors.c \
	mandatory/error_free.c mandatory/main.c mandatory/utils.c mandatory/ft_atof.c mandatory/ft_split.c mandatory/window.c mandatory/check_items.c \
	mandatory/parse.c mandatory/intersections.c mandatory/viewport.c mandatory/cylinder.c mandatory/shadows.c mandatory/translate_events.c \
	mandatory/events.c mandatory/rotate_events.c mandatory/lighting.c mandatory/window_events.c mandatory/rotate_axis.c mandatory/utils_2.c \
	mandatory/add_sp_pl.c mandatory/add_object_cy.c

OBJS = $(SRCS:.c=.o)

B_SRCS = bonus/colors.c bonus/rays.c bonus/camera.c bonus/vector_math.c bonus/vector_operations.c bonus/vectors.c \
	bonus/error_free.c bonus/main.c bonus/utils.c bonus/ft_atof.c bonus/ft_split.c bonus/window.c bonus/check_items.c \
	bonus/parse.c bonus/intersections.c bonus/viewport.c bonus/cylinder.c bonus/shadows.c bonus/events.c bonus/cone.c \
	bonus/rotate_events.c bonus/translate_events.c bonus/rotate_axis.c bonus/lighting.c bonus/normal.c bonus/checks.c \
	bonus/utils_2.c bonus/add_cy_co.c bonus/add_sp_pl.c bonus/add_light_object.c 

B_OBJS = $(B_SRCS:.c=.o)

# Regola per creare l'eseguibile
$(NAME): $(OBJS) $(MINILIBX) $(GET_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(GET_LIB) $(LDFLAGS) -o $@
	@echo "\033[0;96m"
	@echo "             _       _ _____  ______ "
	@echo "            (_)     (_)  __ \|_   __|"
	@echo "  ____   __  _ _ __  _| |__) | | |"
	@echo " /  _ \/ _ \| | '_ \| |  _  /  | |"
	@echo " | | |  | | | | | | | | | \ \  | |"
	@echo " |_| |__| |_|_|_| |_| |_|  \_\ |_|"
	@echo ""
	@echo "         Welcome to miniRT"
	@echo "\033[0m"
	@echo "CONTROLS:"
	@echo "select a light: press 'L'"
	@echo "select the camera: press 'C'"
	@echo "select an object: click on it"
	@echo "deselect an object: click the right mouse button"
	@echo "MOVEMENT:"
	@echo "translate (object, camera or light): use Q/W/E/A/S/D"
	@echo "rotate (object or camera): use N/M and arrow keys"
	@echo "zoom: use the scroll wheel"


$(BONUS_NAME):  $(B_OBJS) $(MINILIBX) $(GET_LIB)
	@$(CC) $(CFLAGS) $(B_OBJS) $(GET_LIB) $(LDFLAGS) -o $@
	@echo "\033[0;96m"
	@echo "             _       _ _____  ______ "
	@echo "            (_)     (_)  __ \|_   __|"
	@echo "  ____   __  _ _ __  _| |__) | | |"
	@echo " /  _ \/ _ \| | '_ \| |  _  /  | |"
	@echo " | | |  | | | | | | | | | \ \  | |"
	@echo " |_| |__| |_|_|_| |_| |_|  \_\ |_|"
	@echo ""
	@echo "         Welcome to miniRT"
	@echo "\033[0m"
	@echo "CONTROLS:"
	@echo "select a light: press 'L'"
	@echo "select the camera: press 'C'"
	@echo "select an object: click on it"
	@echo "deselect an object: click the right mouse button"
	@echo "MOVEMENT:"
	@echo "translate (object, camera or light): use Q/W/E/A/S/D"
	@echo "rotate (object or camera): use N/M and arrow keys"
	@echo "zoom: use the scroll wheel"

# Regola per compilare i filename .o dai filename .c
mandatory/%.o: mandatory/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola per minilibx - compila se esiste
$(MINILIBX): | $(MINI)
	@$(MAKE) -s -C $(MINI)

# Regola per scaricare minilibx SOLO se non esiste
$(MINI):
	@curl -s -L $(MINILIBX_URL) | tar xz
	@mv minilibx-linux-master $(MINI)

# Regola per get_next_line
$(GET_LIB):
	@$(MAKE) -s -C $(GET)

# Regola per pulire i filename oggetto
clean:
	@rm -f $(OBJS) $(B_OBJS)
	@$(MAKE) -s -C $(GET) clean
	@$(MAKE) -s -C $(MINI) clean 2>/dev/null || true
	@echo "Pulizia filename oggetto completata!"

# Regola per pulire tutto (filename oggetto + libreria) - SENZA CONFIGURE
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -s -C $(GET) fclean
	@echo "Pulizia completa (incluso miniRT e get_next_line e minilibx)!"

# Regola per ricompilare tutto
re: fclean all

# Valgrind
val: all
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --track-fds=yes --quiet ./$(NAME) $(BONUS_NAME)

.SILENT:

# Evita errori nel caso i nomi delle regole coincidano con filename reali
.PHONY: all clean fclean re val bonus