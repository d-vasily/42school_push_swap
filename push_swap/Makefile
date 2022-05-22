SRCS =			main_push_swap.c shared/input.c shared/stack_operation.c shared/way_operation.c
SRCS_CHECKER =	main_checker.c shared/input.c shared/stack_operation.c shared/way_operation.c

OBJS_DIR =		objs/
SHARED_DIR = 	shared/

OBJS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})
OBJS_CHECKER =	$(addprefix ${OBJS_DIR}, ${SRCS_CHECKER:.c=.o})

DEPS =			$(addprefix ${OBJS_DIR}, ${SRCS:.c=.d})
DEPS_CHECKER =	$(addprefix ${OBJS_DIR}, ${SRCS_CHECKER:.c=.d})

NAME =			push_swap
CHECKER =		checker

LIBFT =			./libft

HEADER =		push_swap.h

CC =			clang

FLAGS = 		-Wall -Werror -Wextra -O3 -MMD

${OBJS_DIR}%.o: %.c
				${CC} ${FLAGS} -c $< -o $@

all:			${NAME} ${CHECKER}

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR} ${OBJS_DIR}${SHARED_DIR}

${LIBFT}:		FORCE
				@${MAKE} -C ./libft all

${NAME}:		${OBJS_DIR} ${OBJS} ${LIBFT} ${HEADER}
				${CC} ${FLAGS} -L./libft -lft ${OBJS} -o ${NAME}

${CHECKER}:		${OBJS_DIR} ${OBJS_CHECKER} ${LIBFT} ${HEADER}
				${CC} ${FLAGS} -L./libft -lft ${OBJS_CHECKER} -o ${CHECKER}

FORCE:			;

clean:
				@${MAKE} -C ./libft clean
				@rm -rf ${OBJS_DIR}

fclean:			clean
				@${MAKE} -C ./libft fclean
				@rm -f ${NAME} ${CHECKER}

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include		${DEPS} ${DEPS_CHECKER}
