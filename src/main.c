#include <gtk/gtk.h>
#include "video_streaming.h"

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GStreamer Streaming App");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

    GtkWidget *button = gtk_button_new_with_label("Start Streaming");
    g_signal_connect(button, "clicked", G_CALLBACK(start_video_streaming), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
    
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.GStreamer", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}