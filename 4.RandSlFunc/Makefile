CC = g++
STARPU_VERSION=1.3
CPPFLAGS += $(shell pkg-config --cflags starpu-$(STARPU_VERSION))
LDLIBS += $(shell pkg-config --libs starpu-$(STARPU_VERSION))

CPPFLAGS += -O0 -g
#CPPFLAGS += -O3 -Wall -Wextra

# to avoid having to use LD_LIBRARY_PATH
LDLIBS += -Wl,-rpath -Wl,$(shell pkg-config --variable=libdir starpu-$(STARPU_VERSION))
PROGS=RandSlFuncSP

all: $(PROGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $< -c -o $@

RandSlFuncSP: RandSlFuncSP.o

clean:
	rm -f $(PROGS) **/*.o
