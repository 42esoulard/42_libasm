CC			= clang
FLAGS 		= -Wall -Wextra -Werror
NAME 		= libasm.a
SRC_DIR		= source/
SRC 		= ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s
SRCS		= $(addprefix $(SRC_DIR), $(SRC))
OBJS 		= ${SRCS:.s=.o}
NASM 		= nasm 
NASM_FLAGS 	= -f elf64


%.o:		%.s
	$(NASM) $(NASM_FLAGS) $<

$(NAME):	${OBJS}
	ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.phony: 	clean fclean re run