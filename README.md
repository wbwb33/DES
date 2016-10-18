# DES
NIM: 15/381069/PA/16749<br>

# Dokumentasi
Line 46-64 mengenerate 56-bit key dari 64-bit key dengan tabel PC-1.
C0 adalah 28 character pertama dari 56-bit key dan D0 adalah 28 character terakhir dari 56-bit key.<br>
Line 80-135 mengenerate key C(1)-C(16) dan D(1)-D(16) dengan left shift dari C atau D sebelumnya dengan syarat jika i adalah 1,2,9,16 maka dilakukan 1 kali left shift, selain itu dilakukan 2 kali left shift.
Kemudian masing-masing C(i) dan D(i) digabung dan membentuk K(i) dengan panjang 56-bit.<br>
Line 141-204 membuat 56-bit key K(1)-K(16) yang didapat dari gabungan C dan D tadi dan diurutkan berdasarkan tabel PC-2<br>
Line 210-223 memodifikasi plainteks berdasarkan tabel IP.<br>
Line 224-241 plainteks tadi dibagi menjadi dua, L0 dan R0 yang masing-masing memiliki panjang 32-bit.<br>
Line 246-248 mengenerate L(1)-L(16) yang masing-masing adalah R(0)-R(15). L(i)=R(i-1).<br>
Line 251-309 mengekspansi R(0)-R(15) yang memiiki panjang 32-bit agar menjadi 48-bit sesuai dengan Ekspansion Table.<br>
Line 324-329 XOR K(1)-K(16) masing-masing dengan Ekspansi R(1)-R(16) tadi.<br>
Line 337-508 hasil XOR tadi akan disubtitusi sehingga menghasilkan string baru dengan panjang 32-bit sesuai dengan ketentuan Sbox.<br>
Line 513-551 hasil Sbox tadi akan dimodifikasi sesuai dengan Permutation Table sehingga menghasilkan string baru dengan panjang yang sama 32-bit.<br>
Line 560-571 String baru tadi akan di XOR dengan L(i). String baru ini adalah R(i).<br>
Line 594-598 Dibuat string 64-bit baru yang merupakan gabungan R(16) dengan L(16).<br>
Line 600-615 Gabungan R(16) dan L(16) akan dipermutasi sesuai tabel IP^-1.<br>
Hasil permutasi inilah yang merupakan ciphertext-nya.<br>



# Kontribusi
Mencari referensi http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm<br>
Membuat line 600-615 (permutasi tabel IP^-1).<br>
Mengikuti presentasi.
