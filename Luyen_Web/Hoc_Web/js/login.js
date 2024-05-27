const register = document.getElementById("register");

// Xử lý css trong js cho HTML
register.style.textDecoration = "underline";

// Xử lý thẻ a mở trang đăng kí
register.setAttribute("href", "register.html")
register.setAttribute("target", "_blank")

console.log(register);
