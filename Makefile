SERVER_NAME			= server
CLIENT_NAME			= client

SERVER_NAME_BONUS			= server_bonus
CLIENT_NAME_BONUS			= client_bonus

CFLAGS				= -Iincludes -g -fPIE
UTILS				=	src/utils.c \
						src/utils_two.c \


UTILS_BONUS				=	src_bonus/utils_bonus.c \
							src_bonus/utils_two_bonus.c \

SRC_CLIENT			= src/client.c
SRC_SERVER			= src/server.c

SRC_CLIENT_BONUS			= src_bonus/client_bonus.c
SRC_SERVER_BONUS			= src_bonus/server_bonus.c

OBJ_CLIENT			= $(SRC_CLIENT:.c=.o)
OBJ_SERVER			= $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS			= $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS			= $(SRC_SERVER_BONUS:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

##				MANDATORY				##

src/server.o: src/server.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER_NAME): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) $(UTILS)

src/client.o: src/client.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CLIENT_NAME): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) $(UTILS)

##				BONUS					##

src_bonus/server_bonus.o: src_bonus/server_bonus.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER_NAME_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER_BONUS) $(UTILS_BONUS)

src_bonus/client_bonus.o: src_bonus/client_bonus.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CLIENT_NAME_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT_BONUS) $(UTILS_BONUS)


clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean:            clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean $(SERVER_NAME) $(CLIENT_NAME)  

.PHONY:            all clean fclean re
