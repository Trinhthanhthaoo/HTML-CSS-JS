<?php
$sql = "SELECT * FROM books";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        echo "Tiêu đề: " . $row["title"]. " - Tác giả: " . $row["author"]. "<br>";
    }
} else {
    echo "Không có kết quả";
}
$conn->close();
?>
