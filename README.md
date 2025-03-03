# **GStreamer GTK Streaming App**
🚀 **Aplikasi Streaming Video Menggunakan GStreamer & GTK** 🚀  

Aplikasi ini memungkinkan pengguna untuk menangkap video dari **webcam** dan mengirimkannya melalui jaringan menggunakan **UDP streaming** dengan **GStreamer** dan **GTK**.

---

## **🛠️ Fitur**
✅ **Streaming video dari webcam** menggunakan **GStreamer**  
✅ **Dikirim melalui UDP ke komputer lain atau localhost (`127.0.0.1`)**  
✅ **Menggunakan H.264 encoding untuk kompresi video**  
✅ **Dibangun dengan GTK untuk GUI sederhana**  

---


---

## **📥 Instalasi**
### **1️⃣ Instal MSYS2 dan Dependensi GStreamer**
Jika belum memiliki **MSYS2**, unduh dan instal dari:  
🔗 **[https://www.msys2.org/](https://www.msys2.org/)**  

## Setelah itu, **buka MSYS2 MINGW64** dan jalankan perintah berikut:
```sh
pacman -Syu  # Update sistem
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
pacman -S --needed mingw-w64-x86_64-gtk3 mingw-w64-x86_64-gstreamer mingw-w64-x86_64-gst-plugins-base mingw-w64-x86_64-gst-plugins-good mingw-w64-x86_64-gst-libav

## **Cara Menggunakan**
📌 Streaming ke Komputer Sendiri (Localhost)
*Jalankan aplikasi (my_gstreamer_app.exe).*
#*Buka terminal baru, jalankan perintah ini untuk menerima video:

gst-launch-1.0 udpsrc port=5000 caps="application/x-rtp" ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink
🚀 Video akan muncul di layar!
📌 Streaming ke Komputer Lain
#*Atur udpsink di kode (video_streaming.c):

g_object_set(G_OBJECT(sink), "host", "192.168.X.X", "port", 5000, NULL);
Ganti 192.168.X.X dengan IP komputer penerima.

Jalankan aplikasi (my_gstreamer_app.exe).

# *Di komputer penerima, jalankan:

gst-launch-1.0 udpsrc port=5000 caps="application/x-rtp" ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink
🎥 Video dari pengirim akan muncul di komputer penerima!
