#include <gtk/gtk.h>
#include <gst/gst.h>
#include "video_streaming.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    // Inisialisasi GTK dan GStreamer
    gtk_init(&argc, &argv);
    gst_init(&argc, &argv);

    // Membuat Window dan UI
    create_window();

    // Menyiapkan video streaming
    start_video_streaming();

    // Menjalankan GTK Main Loop
    gtk_main();

    return 0;
}