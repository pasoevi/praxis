const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

ctx.fillStyle = 'green';
ctx.fillRect(0, 0, 640, 480);

function putDot(x, y) {
  // console.log(`X: ${x}, Y: ${y}`);
  ctx.fillStyle = 'black';
  ctx.fillRect(x, y, 3, 3);
}

function drawRandom() {
  function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min; //The maximum is exclusive and the minimum is inclusive
  }

  const colors = ["red", "blue", "black", "white", "yellow"];
  const col = colors[getRandomInt(0, colors.length)];
  ctx.fillStyle = col;

  var times = getRandomInt(2, 150);
  for (var i = 0; i < times; i++) {
    const randX = getRandomInt(0, 640)
    const randY = getRandomInt(0, 480);

    ctx.fillRect(randX, randY, 3, 4);
  }
}

function getMousePos(canvas, evt) {
  var rect = canvas.getBoundingClientRect();
  return {
    x: evt.clientX - rect.left,
    y: evt.clientY - rect.top
  };
}

function getMousePos(canvas, evt) {
  var rect = canvas.getBoundingClientRect();
  return {
    x: evt.clientX - rect.left,
    y: evt.clientY - rect.top
  };
}

function relMouseCoords(event) {
  var totalOffsetX = 0;
  var totalOffsetY = 0;
  var canvasX = 0;
  var canvasY = 0;
  var currentElement = this;

  do {
    totalOffsetX += currentElement.offsetLeft - currentElement.scrollLeft;
    totalOffsetY += currentElement.offsetTop - currentElement.scrollTop;
  }
  
  while (currentElement = currentElement.offsetParent)

  canvasX = event.pageX - totalOffsetX;
  canvasY = event.pageY - totalOffsetY;

  return {
    x: canvasX,
    y: canvasY
  }
}
HTMLCanvasElement.prototype.relMouseCoords = relMouseCoords;

function clearCanvas() {
  ctx.fillStyle = 'green';
  ctx.fillRect(0, 0, 640, 480);
}

function dlCanvas() {
  let dt = canvas.toDataURL("image/png");
  /* Change MIME type to trick the browser to downlaod the file instead of displaying it */
  dt = dt.replace(/^data:image\/[^;]*/, "data:application/octet-stream");

  /* In addition to <a>'s "download" attribute, you can define HTTP-style headers */
  dt = dt.replace(/^data:application\/octet-stream/, "data:application/octet-stream;headers=Content-Disposition%3A%20attachment%3B%20filename=Canvas.png");

  this.href = dt;
}

ccanvas.addEventListener("mousedown", function(ev) {
    paint = true;
}, false);

anvas.addEventListener("mouseup", function(ev) {
    paint = false;
}, false);

let paint = false;

canvas.addEventListener("mousemove", function(ev) {
   console.log("ok"); 
        if (paint) {
            const coords = getMousePos(canvas, ev);

            putDot(coords.x, coords.y);
            console.log(`X: ${ev.clientX}, Y: ${ev.clientY}`);
        }
}, false);

document.getElementById("dl").addEventListener("click", dlCanvas, false);
document.getElementById("reset").addEventListener("click", clearCanvas, false);
document.getElementById("random").addEventListener("click", drawRandom, false);
