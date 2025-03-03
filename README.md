GStreamer GTK Streaming App
🚀 Aplikasi Streaming Video Menggunakan GStreamer & GTK 🚀

Aplikasi ini memungkinkan pengguna untuk menangkap video dari webcam dan mengirimkannya melalui jaringan menggunakan UDP streaming dengan GStreamer dan GTK.

🛠️ Fitur
✅ Streaming video dari webcam menggunakan GStreamer
✅ Dikirim melalui UDP ke komputer lain atau localhost (127.0.0.1)
✅ Menggunakan H.264 encoding untuk kompresi video
✅ Dibangun dengan GTK untuk GUI sederhana

📂 Struktur Proyek
less
Copy
Edit
📂 gstreamgtk
 ├── 📂 src
 │    ├── main.c                // Kode utama aplikasi GTK
 │    ├── video_streaming.c      // Pipeline streaming dengan GStreamer
 │    ├── video_streaming.h      // Header file
 ├── makefile                    // Build script
 ├── README.md                    // Dokumentasi proyek
 ├── my_gstreamer_app.exe        // Output program setelah build
📥 Instalasi
1️⃣ Instal MSYS2 dan Dependensi GStreamer
Jika belum memiliki MSYS2, unduh dan instal dari:
🔗 https://www.msys2.org/

Setelah itu, buka MSYS2 MINGW64 dan jalankan perintah berikut:

sh
Copy
Edit
pacman -Syu  # Update sistem
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
pacman -S --needed mingw-w64-x86_64-gtk3 mingw-w64-x86_64-gstreamer mingw-w64-x86_64-gst-plugins-base mingw-w64-x86_64-gst-plugins-good mingw-w64-x86_64-gst-libav
⚙️ Cara Build dan Jalankan
1️⃣ Build Aplikasi
Jalankan perintah ini di MSYS2 MINGW64:

sh
Copy
Edit
make
Jika tidak memiliki make, gunakan:

sh
Copy
Edit
gcc src/main.c src/video_streaming.c -o my_gstreamer_app `pkg-config --cflags --libs gtk+-3.0 gstreamer-1.0`
2️⃣ Jalankan Aplikasi
sh
Copy
Edit
./my_gstreamer_app.exe
Klik tombol "Start Streaming" untuk mulai mengirim video.

📡 Cara Menggunakan
🔹 Streaming ke Komputer Sendiri (Localhost)
Jalankan aplikasi (my_gstreamer_app.exe).
Buka terminal baru, jalankan perintah untuk menerima video:
sh
Copy
Edit
gst-launch-1.0 udpsrc port=5000 caps="application/x-rtp" ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink
🚀 Video akan muncul di layar!
🔹 Streaming ke Komputer Lain
Atur udpsink di kode (video_streaming.c):

c
Copy
Edit
g_object_set(G_OBJECT(sink), "host", "192.168.X.X", "port", 5000, NULL);
Ganti 192.168.X.X dengan IP komputer penerima.

Jalankan aplikasi (my_gstreamer_app.exe).

Di komputer penerima, jalankan:

sh
Copy
Edit
gst-launch-1.0 udpsrc port=5000 caps="application/x-rtp" ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink
🎥 Video dari pengirim akan muncul di komputer penerima!

🔧 Troubleshooting
❌ Error: "no element avdec_h264"
✔️ Instal gst-libav:

sh
Copy
Edit
pacman -S mingw-w64-x86_64-gst-libav
❌ Tidak ada video di penerima
✔️ Cek firewall & port UDP 5000
✔️ Coba matikan firewall sementara di Windows:

sh
Copy
Edit
netsh advfirewall set allprofiles state off
✔️ Cek apakah komputer pengirim bisa menjangkau penerima:

sh
Copy
Edit
ping 192.168.X.X
📜 Lisensi
Proyek ini menggunakan lisensi MIT. Silakan digunakan, dimodifikasi, dan dibagikan sesuai kebutuhan.

🎯 Kesimpulan
✅ Aplikasi GTK + GStreamer untuk streaming video dengan UDP
✅ Bisa dikirim ke localhost atau komputer lain
✅ Mudah dikembangkan dan dikustomisasi

🚀 Selamat mencoba! Jika ada pertanyaan, jangan ragu untuk bertanya! 🚀