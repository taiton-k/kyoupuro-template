CC = clang++
CFLAGS = -std=c++17 -Wall -Wextra -Wno-unused -O0 -DLOCAL -D_GLIBCXX_DEBUG
SANITIZE = undefined,address

TARGET = a.out
SRCS = main.cpp
OBJS    = $(SRCS:.cpp=.o)
INCDIR = ~/Documents/KyouPuro/c++/


$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS) -fsanitize=$(SANITIZE)

$(OBJS): $(SRCS)
	ccache $(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCS) -fsanitize=$(SANITIZE)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
