let cities = [];
let recordDistance;
let bestSoFar = [];

function setup() {
    createCanvas(400, 300);
    frameRate(7);

    // Generate random cities
    // for (var i = 0; i < TOTAL_CITIES; i++) {
        
    // }

    
}

function draw() {
    background(0);
    fill(255);

    if (cities.length === 0) {
	return;
    }

    // Draw cities
    cities.forEach(function (city) {
	ellipse(city.x, city.y, 10, 10);
    });

    // Draw paths between cities
    stroke(255);
    strokeWeight(2);
    noFill();
    beginShape();
    cities.forEach(function (city) {
        vertex(city.x, city.y);
    });
    endShape();

    // Draw the best travel combination so far in a different color
    stroke(250, 0, 250);
    strokeWeight(4);
    noFill();
    beginShape();
    bestSoFar.forEach(function (city) {
        vertex(city.x, city.y);
    });
    endShape();

    const i = floor(random(cities.length));
    const j = floor(random(cities.length));
    swap(cities, i, j);

    var d = calcDistance(cities);
    if (d < recordDistance) {
	recordDistance = d;
	bestSoFar = cities.slice();
	console.log(recordDistance);
    }

    
}

function mousePressed() {
    // let v = createVector(random(width), random(height));
    let v = createVector(mouseX, mouseY);
    cities.push(v);

    bestSoFar = cities.slice();
    recordDistance = calcDistance(cities);
}

function swap (a, i, j) {
    const tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

function calcDistance(points) {
    let sum = 0;

    for (let i = 0; i < points.length -1; i++) {
	const nextPoint = points[i + 1];
	const d = dist(points[i].x, points[i].y, nextPoint.x, nextPoint.y);
	sum += d;
    }

    return sum;
}

