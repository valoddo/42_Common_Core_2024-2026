# Nome dell'eseguibile
NAME = megaphone

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

# Regola per creare la libreria statica
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 
	@echo "Eseguibile $(NAME) creato con successo!"

# Regola per compilare i file .o dai file .c
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Regola per pulire i file oggetto
clean:
	@rm -f $(OBJS)
	@echo "Pulizia file oggetto completata!"

# Regola per pulire tutto (file oggetto + libreria)
fclean: clean
	@rm -f $(NAME)
	@echo "Pulizia completa (incluso $(NAME))!"

# Regola per ricompilare tutto
re: fclean all

# Evita errori nel caso i nomi delle regole coincidano con file reali
.PHONY: all clean fclean re