# Nome dell'eseguibile
NAME = mstack

# Compilatore e flag, -c compila i file .c e crea i file oggetto singolarmente
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g  -Wshadow --std=c++98

# Regola per compilare tutto
all: $(NAME)

# Lista dei file sorgenti e oggetti
SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Headers da monitorare (aggiungi qui tutti gli header e tpp)
HEADERS = 

# Regola per creare l'eseguibile
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 
	@echo "Eseguibile $(NAME) creato con successo!"

# Regola per compilare i file .o dai file .c
%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Includi le dipendenze generate automaticamente
-include $(DEPS)

# Regola per pulire i file oggetto
clean:
	@rm -f $(OBJS) $(DEPS)
	@echo "Pulizia file oggetto completata!"

# Regola per pulire tutto (file oggetto + libreria)
fclean: clean
	@rm -f $(NAME)
	@echo "Pulizia completa (incluso $(NAME))!"

# Regola per ricompilare tutto
re: fclean all

# Evita errori nel caso i nomi delle regole coincidano con file reali
.PHONY: all clean fclean re