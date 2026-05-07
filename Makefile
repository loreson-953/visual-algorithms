CC = gcc
TARGET = visual_algorithms
SRCS = main.c ui.c algorithms.c
CFLAGS = -lncurses -ltinfo

main:
	${CC} -o ${TARGET} ${CFLAGS} ${SRCS}

clean:
	rm -f ${TARGET}
