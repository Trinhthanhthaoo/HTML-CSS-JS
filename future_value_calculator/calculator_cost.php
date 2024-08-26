<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tính tiền khoản vay</title>
</head>
<body>
    <form method="POST" action="">
        <label for="tienvay">Tiền vay ($):</label>
        <input type="number" id="tienvay" name="tienvay" step="0.01" required> <br><br>
        
        <label for="lai">Lãi suất hàng năm (%):</label>
        <input type="number" id="lai" name="lai" step="0.01" required> <br><br>
        
        <label for="year">Thời gian vay (năm):</label>
        <input type="number" id="year" name="year" required> <br><br>
        
        <button type="submit" name="calculator">Tính</button>
    </form>
    
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['calculator'])) {
        $tienvay = $_POST['tienvay'];
        $lai = $_POST['lai'];
        $year = $_POST['year'];

        // Chuyển lãi suất hàng năm thành lãi suất hàng tháng
        $r = $lai / 100 / 12;
        // Tổng số tháng vay
        $n = $year * 12;

        // Tính khoản phải trả hàng tháng
        if ($r == 0) {
            $monthlyPayment = $tienvay / $n; // Trường hợp không có lãi suất
        } else {
            $monthlyPayment = $tienvay * $r * pow(1 + $r, $n) / (pow(1 + $r, $n) - 1);
        }

        echo "<h3>Số tiền phải trả hàng tháng: $" . number_format($monthlyPayment, 2) . "</h3>";
    }
    ?>
</body>
</html>
// php -S localhost:8000