function loadCanvas() {
var canvas = document.getElementById('background');
if(!canvas.getContext('2d'))
{
document.getElementById('background').style.display = 'none';
document.getElementById('no-canvas').style.display = 'block';
return;
}
canvas.width = 10000;
canvas.height = 500;
drawPlan(canvas);
}
function drawPlan(canvas) {
var ctx = canvas.getContext('2d');
ctx.fillStyle = '#887';
ctx.fillRect(0, 0, 10000, 300);

document.body.style.background = `url(${canvas.toDataURL()}) no-repeat`;}