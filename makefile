CC=x86_64-w64-mingw32-gcc
CFLAGS=`pkg-config --cflags gtk+-3.0 gstreamer-1.0 glib-2.0 gobject-2.0`
LIBS=`pkg-config --libs gtk+-3.0 gstreamer-1.0 glib-2.0 gobject-2.0`

SRC=src/main.c src/video_streaming.c
OBJ=build/main.o build/video_streaming.o
EXEC=my_gstreamer_app.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Compile each source file into object file in the build directory
build/%.o: src/%.c
	mkdir -p build
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf build $(EXEC)
