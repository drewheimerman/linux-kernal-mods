SOURCES = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SOURCES))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
