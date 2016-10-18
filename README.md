# DES

# Dokumentasi
Line 46-64 mengenerate 56-bit key dari 64-bit key dengan tabel PC-1.<br>
C0 adalah 28 character pertama dari 56-bit key dan D0 adalah 28 character terakhir dari 56-bit key.
Line 80-135 mengenerate key C1-C16 dan D1-D16 dengan left shift dari C atau D sebelumnya dengan syarat jika i adalah 1,2,9,16 maka dilakukan 1 kali left shift, selain itu dilakukan 2 kali left shift.
Kemudian masing-masing Ci dan Di digabung dan membentuk Ki dengan panjang 56-bit
Line 141-204 membuat 56-bit key K1-K16 yang didapat dari gabungan C dan D tadi dan diurutkan berdasarkan tabel PC-2
Line 244-590 membuat L1-L16 dan R1-R16

# Kontribusi
Mencari referensi http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm
Mengikuti presentasi
