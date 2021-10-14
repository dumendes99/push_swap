NAME = push_swap

CFLAGS = -Wall -Werror -Wextra 
CC = clang 

INCLUDE = ./include

SOURCES =  ./sources

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects

SOURCES_FILES = teste.c \

SOURCES = $(addprefix $(SOURCES_PATH)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(subst .c,.o,$(SOURCES_FILES)))

SAFE_MAKEDIR = mkdir -p
REMOVE = rm -rf 

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) -g $(OBJECTS) -o $(NAME)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -g -I $(INCLUDE) -o $@ -c $<

re: fclean all 

clean: 
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean 
	$(REMOVE) $(NAME)