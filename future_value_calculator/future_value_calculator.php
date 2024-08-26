<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Future Value Calculator</title>
</head>
<body>
    <h2>Future Value Calculator</h2>
    <form method="POST" action="">
        <label for="investment">Investment Amount:</label>
        <input type="number" id="investment" name="investment" required><br><br>
        
        <label for="interest">Yearly Interest Rate (%):</label>
        <input type="number" step="0.01" id="interest" name="interest" required><br><br>
        
        <label for="years">Number of Years:</label>
        <input type="number" id="years" name="years" required><br><br>
        
        <button type="submit" name="calculate">Calculate</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['calculate'])) {
        $investment = $_POST['investment'];
        $interest = $_POST['interest'];
        $years = $_POST['years'];

        // Calculate the future value
        $futureValue = $investment * pow(1 + ($interest / 100), $years);

        echo "<h3>Future Value: $" . number_format($futureValue, 2) . "</h3>";
    }
    ?>
</body>
</html>
