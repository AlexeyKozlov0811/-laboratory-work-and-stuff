function loadCanvas() {
var canvas = document.getElementById('housesPlan');
if(!canvas.getContext('2d'))
{
document.getElementById('housesPlan').style.display = 'none';
document.getElementById('no-canvas').style.display = 'block';
return;
}
canvas.width = 480;
canvas.height = 320;
drawPlan(canvas);
}
function drawPlan(canvas) {
var ctx = canvas.getContext('2d');

// стіни кімнати
ctx.strokeRect(12, 12, 456, 296);
ctx.strokeRect(20, 20, 440, 280);
// двері
ctx.strokeRect(12, 180, 8, 80);
ctx.beginPath();
ctx.moveTo(20, 260);
ctx.lineTo(80, 200);
ctx.stroke();
// вікно
ctx.strokeRect(460, 100, 8, 120);
ctx.lineWidth = 1;
ctx.beginPath();
ctx.moveTo(464, 102);
ctx.lineTo(464, 220);
ctx.stroke();
ctx.lineWidth = 4;

//стільці
ctx.fillStyle = '#fff';
ctx.beginPath();
ctx.arc(105, 110, 30, 0, 90, false);
ctx.fill();
ctx.stroke();

ctx.beginPath();
ctx.arc(235, 110, 30, 0, 90, false);
ctx.fill();
ctx.stroke();

ctx.beginPath();
ctx.arc(365, 110, 30, 0, 90, false);
ctx.fill();
ctx.stroke();

// стіл
ctx.fillStyle = '#00f';
ctx.fillRect(20, 20, 440, 70);
ctx.strokeRect(21, 21, 438, 70);

// монітори
ctx.fillStyle = '#fff';
ctx.beginPath();
ctx.moveTo(50, 40);
ctx.lineTo(60, 30);
ctx.lineTo(150, 30);
ctx.lineTo(160, 40);
ctx.fill();
ctx.stroke();

ctx.beginPath();
ctx.moveTo(180, 40);
ctx.lineTo(190, 30);
ctx.lineTo(280, 30);
ctx.lineTo(290, 40);
ctx.fill();
ctx.stroke();

ctx.beginPath();
ctx.moveTo(310, 40);
ctx.lineTo(320, 30);
ctx.lineTo(410, 30);
ctx.lineTo(420, 40);
ctx.fill();
ctx.stroke();

// клавіатури
ctx.fillRect(70, 50, 70, 30);
ctx.strokeRect(70, 50, 70, 30);

ctx.fillRect(200, 50, 70, 30);
ctx.strokeRect(200, 50, 70, 30);

ctx.fillRect(330, 50, 70, 30);
ctx.strokeRect(330, 50, 70, 30);
}