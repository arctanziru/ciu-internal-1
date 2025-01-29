Misal `x = p - q` `y = p % q` `p = kq + y` (ingat sifat modular), lalu `x + q = kq + y` `x - y  = (k-1)q`. Lakukan hal yang sama dengan p yang baru. `u = p2 - q` `v = p2 % q` `p2 = kq + v` `u + q = kq + v` `u - v = (k-1)q`

Dari sini kita tau bahwa `x - y` dan `u - v` merupakan kelipatan q, jadi `q = gcd(x - y, u - v)`. Belum sampai situ, pastikan hasil gcd nya itu prima, karna boleh jadi hasil gcd tersebut masih menyisahkan bilangan k lain. Simplenya ambil factor prima terbesarnya. 

Setelah mendapatkan q anda bisa mencari p, lalu n, perhatikan bahwa FLAGnya relatif kecil, yakni FLAG < q. Jadi kita cukup cari d menggunakan inverse e mod q-1.
