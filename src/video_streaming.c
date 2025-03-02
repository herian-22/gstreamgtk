#include <gst/gst.h>
#include "video_streaming.h"

static GstElement *pipeline;

void start_video_streaming() {
    // Membuat pipeline GStreamer
    pipeline = gst_pipeline_new("video-pipeline");

    // Elemen GStreamer untuk sumber dan pengkodean
    GstElement *source = gst_element_factory_make("v4l2src", "source");
    GstElement *encoder = gst_element_factory_make("x264enc", "encoder");
    GstElement *payloader = gst_element_factory_make("rtph264pay", "payloader");
    GstElement *sink = gst_element_factory_make("udpsink", "sink");

    // Periksa apakah elemen berhasil dibuat
    if (!pipeline) {
        g_printerr("Failed to create pipeline\n");
        return;
    }
    if (!source) {
        g_printerr("Failed to create source element\n");
        return;
    }
    if (!encoder) {
        g_printerr("Failed to create encoder element\n");
        return;
    }
    if (!payloader) {
        g_printerr("Failed to create payloader element\n");
        return;
    }
    if (!sink) {
        g_printerr("Failed to create sink element\n");
        return;
    }

    // Menambahkan elemen-elemen ke pipeline
    gst_bin_add_many(GST_BIN(pipeline), source, encoder, payloader, sink, NULL);

    // Menghubungkan elemen-elemen
    if (!gst_element_link_many(source, encoder, payloader, sink, NULL)) {
        g_printerr("Failed to link GStreamer elements\n");
        return;
    }

    // Mengatur pipeline ke playing
    GstStateChangeReturn ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Failed to start pipeline\n");
        return;
    }

    g_print("Streaming video...\n");
}