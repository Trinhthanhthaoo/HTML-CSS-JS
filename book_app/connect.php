<?php
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "book_app";

// Tạo kết nối
$conn = new mysqli($servername, $username, $password, $dbname);

// Kiểm tra kết nối
if ($conn->connect_error) {
    die("Kết nối thất bại: " . $conn->connect_error);
} else {
    echo "Kết nối thành công!";
}

// Đóng kết nối
$conn->close();
?>
