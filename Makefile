CC = gcc
TARGET = visual_algorithms
SRCS = main.c ui.c algorithms.c

include config.mk

main:
	${CC} -o ${TARGET} ${CFLAGS} ${SRCS}

clean:
	rm -f ${TARGET}
