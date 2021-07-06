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
ctx.fillStyle = '#00f';
// blue
// ctx.strokeStyle = `#f00`;
// red
// ctx.lineWidth = 4;
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
// диван
ctx.fillRect(180, 200, 220, 90);
ctx.strokeRect(180, 200, 16, 90);
ctx.strokeRect(384, 200, 16, 90);

ctx.strokeRect(196, 266, 188, 24);
//TV
ctx.beginPath();
ctx.moveTo(200, 40);
ctx.lineTo(210, 30);
ctx.lineTo(360, 30);
ctx.lineTo(370, 40);
ctx.fill();
ctx.stroke();
// стіл
ctx.beginPath();
ctx.arc(80, 80, 50, 0, 90, false);
ctx.fill();
ctx.stroke();
}