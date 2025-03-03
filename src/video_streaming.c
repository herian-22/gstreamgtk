#include <gst/gst.h>
#include "video_streaming.h"

static GstElement *pipeline;

void start_video_streaming() {
    gst_init(NULL, NULL);

    pipeline = gst_pipeline_new("video-pipeline");

    GstElement *source = gst_element_factory_make("autovideosrc", "source");
    GstElement *videoconvert = gst_element_factory_make("videoconvert", "convert");
    GstElement *encoder = gst_element_factory_make("x264enc", "encoder");
    GstElement *payloader = gst_element_factory_make("rtph264pay", "payloader");
    GstElement *sink = gst_element_factory_make("udpsink", "sink");

    if (!pipeline || !source || !videoconvert || !encoder || !payloader || !sink) {
        g_printerr("Failed to create GStreamer elements\n");
        return;
    }

    
    g_print("Pipeline created successfully!\n");

 
    g_object_set(G_OBJECT(sink), "host", "127.0.0.1", "port", 5000, "sync", FALSE, NULL);


    gst_bin_add_many(GST_BIN(pipeline), source, videoconvert, encoder, payloader, sink, NULL);
    
 
    if (!gst_element_link_many(source, videoconvert, encoder, payloader, sink, NULL)) {
        g_printerr("Failed to link GStreamer elements\n");
        gst_object_unref(pipeline);
        return;
    }

    g_print("Pipeline linked successfully!\n");

    
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    g_print("Pipeline is now playing!\n");
}