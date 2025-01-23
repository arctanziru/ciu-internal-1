<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Looking for Itinerary</title>
</head>
<body>
    <h1>Where is the Itinerary</h1>
    <hr>
    <div>
        <?php
        // Direktori dasar aplikasi
        $base_dir = __DIR__;
        // Direktori private (tempat menyimpan flag.txt)
        $private_dir = realpath($base_dir . '/../private'); // Folder 'private' berada di luar root

        // Ambil parameter 'page' dari URL
        $page = $_GET['page'] ?? 'home'; // Default ke 'home'

        // Blokir traversal langsung tanpa encoding
        if (strpos($page, '..') !== false || strpos($page, '/') !== false) {
            echo "<p style='color: red;'>Access denied: traversal must be encoded.</p>";
            exit;
        }

        // Dekode karakter URL
        $decoded_page = urldecode($page);

        // Blokir traversal path setelah decoding
        if (strpos($decoded_page, '..') !== false || strpos($decoded_page, '/') !== false) {
            echo "<p style='color: red;'>Access denied: decoded traversal patterns are not allowed.</p>";
            exit;
        }

        // Tentukan path file di direktori private
        $file_path = realpath($private_dir . '/' . $decoded_page);

        // Validasi path: hanya file di direktori private yang bisa diakses
        if ($file_path === false || strpos($file_path, $private_dir) !== 0) {
            echo "<p style='color: red;'>Invalid file path.</p>";
            exit;
        }

        // Cek apakah file ada
        if (file_exists($file_path)) {
            include($file_path);
        } else {
            echo "<p style='color: red;'>File not found.</p>";
        }
        ?>
    </div>
</body>
</html>
