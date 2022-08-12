SERVER_NAME        := server
CLIENT_NAME        := client
CFLAGS            := -Iincludes -g -fPIE
FT_PRINTF_SRC    := ft_printf
FT_PRINTF_LIB    := libft/libftprintf.a
UTILS				:= src/utils.c
SRC_CLIENT        := src/client.c
SRC_SERVER        := src/server.c

OBJ_CLIENT        := $(SRC_CLIENT:.c=.o)
OBJ_SERVER        := $(SRC_SERVER:.c=.o)
PATH_LIB        = libft

all: $(PATH_LIB) $(FT_PRINTF_LIB) $(SERVER_NAME) $(CLIENT_NAME)

$(PATH_LIB):
	mkdir -p $(PATH_LIB)

$(FT_PRINTF_LIB):
	 make -C $(FT_PRINTF_SRC) all

src/server.o: src/server.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER_NAME): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) $(FT_PRINTF_LIB) $(UTILS)

src/client.o: src/client.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(CLIENT_NAME): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) $(FT_PRINTF_LIB) $(UTILS)

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(SERVER_NAME) $(CLIENT_NAME)
	:make -C $(FT_PRINTF_SRC) clean

fclean:            clean
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@$(RM) $(FT_PRINTF_LIB)
	make -C $(FT_PRINTF_SRC) fclean

re: fclean $(FT_PRINTF_LIB) $(SERVER_NAME) $(CLIENT_NAME)

.PHONY:            all clean fclean re
