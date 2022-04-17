CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror
CLINT 	= clint.c utils.c utils_convert.c 
SERVER 	= server.c utils.c utils_convert.c 
NAMECL 	= client
NAMESR 	= server

all: $(NAMECL) $(NAMESR)
$(NAMECL):
	$(CC) $(FLAGS) $(CLINT) -o client
$(NAMESR):
	$(CC) $(FLAGS) $(SERVER) -o server
clean:
	rm -rf client server
fclean: clean
re: fclean all
.PHONY: clean fclean re all
