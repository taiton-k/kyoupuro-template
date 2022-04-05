CC = ccache g++
CFLAGS = -std=c++17 -Wall -Wextra -Wno-unused -O0 -DLOCAL -D_GLIBCXX_DEBUG

TARGET = a.out
SRCS = main.cpp
OBJS    = $(SRCS:.cpp=.o)
INCDIR = ~/Documents/KyouPuro/c++/


$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
