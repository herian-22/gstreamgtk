CC = gcc
CFLAGS = -Iinclude `pkg-config --cflags gtk+-3.0 gstreamer-1.0 glib-2.0 gobject-2.0`
LIBS = `pkg-config --libs gtk+-3.0 gstreamer-1.0 glib-2.0 gobject-2.0`

SRC = src/main.c src/video_streaming.c src/ui.c
OBJ = build/main.o build/video_streaming.o build/ui.o
EXEC = my_gstreamer_app

# Semua target
all: $(EXEC)

# Membuat executable dengan objek
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Kompilasi setiap file sumber menjadi file objek di direktori build
build/%.o: src/%.c
	mkdir -p build
	$(CC) -c $< -o $@ $(CFLAGS)

# Membersihkan file objek dan executable
clean:
	rm -rf build $(EXEC)