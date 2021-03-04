// GLOBAL SCOPE
{
var CANVAS_WIDTH;
var CANVAS_HEIGHT;

var paddle = new Paddle();

var ballManager = new BallManager();
var bm = new BrickManager();
var im = new ItemManager();
var score = 0;

// entry point
function main() {
	var canvas = document.getElementById("canvas1");
	var canvas2 = document.getElementById("canvas2");
	
	window.CANVAS_WIDTH = canvas.width;
	window.CANVAS_HEIGHT = canvas.height;
	
	setInterval(draw, 1000/60, canvas.getContext("2d"));
	setInterval(drawBricks, 1000/100, canvas2.getContext("2d"));
	setInterval(updateHUD, 1000);
	
	document.addEventListener("keydown", keyPressed, false);
	document.addEventListener("keyup", keyReleased, false);
	document.addEventListener("mousemove", mouseMoved, false);
	
	// create the bricks
	bm.make();
	
	// spawn initial ball
	ballManager.getBalls().push(new Ball(850 / 2, 350, 9));
}
	
function updateHUD(){
	$("#balls").text(ballManager.getBalls().length)
	$("#score").text(score)
}

function keyPressed(e) {
	paddle.keyPressed(e.keyCode);
}

function keyReleased(e) {
	paddle.keyReleased(e.keyCode);
}

function mouseMoved(e) {
	paddle.mouseMoved(e);
}

function draw(ctx) {
	ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
	
	// update
	paddle.update();
	ballManager.update();	
	im.update();
	
	// check for game over
	if(ballManager.getBalls().length == 0) {
		var path = window.location.href + "../../../../html/pages/games.html"
		alert("Game Over :( (too many balls lost)");
		window.location.href = path;
	}
	
	if(bm.getBricks().length == 0) {
		var path = window.location.href + "../../../../html/pages/games.html"
		alert("You won. No more levels to finish.");
		window.location.href = path;
	}
		
	// handle collisions	
	paddle.hitBall(ballManager, ctx);
	bm.collideWithBall(ballManager);
	im.collideWithPlayer(paddle);
	
	// draw entities
	ballManager.draw(ctx);
	paddle.draw(ctx);
	
	// draw Items
	im.draw(ctx);
}

function drawBricks(brick_ctx) {
	brick_ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
	bm.draw(brick_ctx);	
}

// the ^paddle class
function Paddle() {
	
	var x = 850 / 2 - 150 / 2;
	var y = 519;
	var r = 30;
	var rad2 = r * 2;
	var oldRad = r;

	var speed = 3.5;
	var dx = 0;
	
	var hasDoubledRadius = false;
	var startTime = 0;
	var timeWithEffect = 0;
	
	var color = {r: 175, g: 255, b: 255};
	
	var checkBounds = function() {
		if(x > CANVAS_WIDTH - r) {
			x = CANVAS_WIDTH - r;
		}
		
		if(x < r) {
			x = r;
		}
	}
	
	var handleDoubleRadiusItem = function (){
		// enlarge when item is used
		if(hasDoubledRadius) {
			if(r < rad2) {
				r++;
			}
			var elapsedWithDoubledRad = (new Date() - startTime);
			if(elapsedWithDoubledRad > timeWithEffect) {
				hasDoubledRadius = false;
			}
		} else {
			if(r > oldRad) {
				r--;
			}
		}
	}
		
	this.update = function() {
		handleDoubleRadiusItem();
		
		x += dx;
		y = CANVAS_HEIGHT - r;
		checkBounds();
	}
		
	this.draw = function(ctx) {
		ctx.beginPath();
		ctx.fillStyle = "rgb(" + color.r +", " + color.g +", " + color.b +")"
		ctx.arc(x, y, r, 0, 2 * Math.PI);
		ctx.fill();
	}
	
	this.hasDoubleRadiusFor = function(delay) {
		startTime = new Date();
		timeWithEffect = delay;
		hasDoubledRadius = true;
	}
	
	this.hitBall = function(ball_m, ctx) {
		for(var i = 0; i < ball_m.getBalls().length; i++) {
			var ball = ball_m.getBalls()[i];
			
			var deltaX = x - ball.getX();
			var deltaY = y - ball.getY();
			
			var dist = Math.sqrt((deltaX * deltaX) + (deltaY * deltaY));
				
			// I have a collision
			if(dist < r + ball.getRad()) {
				// normalized surface normal of circle
				var normX = deltaX / dist;
				var normY = deltaY / dist;

				// normailized ball's dx and dy
				var normBallDeltaMag = Math.sqrt((ball.getDX() * ball.getDX()) + (ball.getDY() * ball.getDY()));
				var normDX = ball.getDX() / normBallDeltaMag;
				var normDY = ball.getDY() / normBallDeltaMag;
					
				// angle of refection via normailized vectors
				var v2x = normDX - ((2 * normX)*(2 * normX))*normX;
				var v2y = normDY - ((2 * normY)*(2 * normY))*normY;
				
				var mag = Math.sqrt((v2x * v2x) + (v2y * v2y));

				// normalized refected vector
				v2x /= mag;
				v2y /= mag;
				
				ball.makeFaster(0.6);
				
				// scale it up to the ball's original speed;
				v2x *= ball.getSpeed();
				v2y *= ball.getSpeed();
			
				ball.setDX(v2x);
				ball.setDY(v2y);
				
				// use circle parametrics to find point on circumfrance given angle
				var angle = Math.atan2(deltaY, deltaX);
				
				var circum_x = x + (r + ball.getRad()) * -Math.cos(angle);
				var circum_y = y + (r + ball.getRad()) * -Math.sin(angle);
				ball.setX(circum_x);
				ball.setY(circum_y);
			}
		}
	}
	
	this.keyPressed = function(keyCode) {
		if(keyCode == 39) {
			dx = speed;
		}
		
		if(keyCode == 37) {
			dx = -speed;
		}
	}
	
	this.keyReleased = function(keyCode) {
		if(keyCode == 39) {
			dx = 0;
		}
		
		if(keyCode == 37) {
			dx = 0;
		}
	}
	
	this.mouseMoved = function(e) {
		x = e.clientX - document.getElementById("canvas1").offsetLeft;
		checkBounds();
	}
	
	this.getX = function() {
		return x;
	}
	
	this.getY = function() {
		return y;
	}
	
	this.getRad = function() {
		return r;
	}
}

// the ^ball class
function Ball(x, y, r) {
	this.x = x;
	this.y = y;
	this.r = r;
	
	var speed = 2;
	var MAX_SPEED = 9;
	
	var dx = 0;
	var dy = speed;
	var shouldRemove = false;

	
	this.update = function() {
		x += dx;
		y += dy;
		
		if(x > CANVAS_WIDTH - r) {
			x = CANVAS_WIDTH - r;
			dx = -dx;
		}
		
		// -speed
		if(x < r) {
			x = r;
			dx = -dx;
		}
		
		if(y > CANVAS_HEIGHT-r) {
			y = CANVAS_HEIGHT-r; 
			dy = -dy;
			shouldRemove = true;
		}
		
		// -speed
		if(y < r) {
			y = r;
			dy = -dy;
		}
	}
	
	this.draw = function(ctx) {
		ctx.beginPath();
		ctx.fillStyle = "rgb(255, 175, 255)"
		if(speed >= MAX_SPEED) {
			ctx.fillStyle = "rgb(255, 175, 175)"
		}
		ctx.arc(x, y, r, 0, 2 * Math.PI);
		ctx.fill();
	}
	
	this.getDY = function(){
		return dy;
	}
	
	this.setDY = function(val) {
		dy = val;
	}
	
	this.getDX = function(){
		return dx;
	}
	
	this.setDX = function(val) {
		dx = val;
	}
	
	this.getX = function(){
		return x;
	}
	
	this.setX = function(val) {
		x = val;
	}
	
	this.getY = function(){
		return y;
	}
	
	this.isShouldRemove = function() {
		return shouldRemove;
	}
	
	this.setY = function(val) {
		y = val;
	}
	
	this.getRad = function(){
		return r;
	}
	
	this.getSpeed = function() {
		return speed;
	}
	
	this.makeFaster = function(amt) {
		speed += amt;
		if(speed > MAX_SPEED)
			speed = MAX_SPEED;
	}
}

// 

// the ^ball manager
function BallManager() {
	var balls = new Array();
	
	this.getBalls = function() {
		return balls;
	}
	
	this.update = function() {
		for(var i = 0; i < balls.length; i++) {
			if(balls[i].isShouldRemove()) {
				balls.splice(i, 1);
				i--;
			}
			balls[i].update();
		}
	}
	
	this.draw = function(ctx) {
		for(var i = 0; i < balls.length; i++) {
			balls[i].draw(ctx);
		}
	}
	
	this.spliteIntoMultiBall = function(ball, amt) {
		for(var i = 0; i < balls.length; i++) {
			if(balls[i] === ball) {
				for(var j = 0; j < amt; j++) {
					var ball = new Ball(ball.getX(), ball.getY(), ball.getRad());
					ball.setDX(Math.random() * ball.getSpeed());
					ball.setDY(Math.random() * ball.getSpeed());
					balls.push(ball);
				}
				return;
			}
		}
	}
	
	this.spliteIntoMultiBallForEachBall = function(amt) {
		var initLength = balls.length;
		for(var i = 0; i < initLength; i++) {
			for(var j = 0; j < amt; j++) {
				var ball = new Ball(balls[i].getX(), balls[i].getY(), balls[i].getRad());
				ball.setDX(Math.random() * balls[i].getSpeed());
				ball.setDY(Math.random() * balls[i].getSpeed());
				balls.push(ball);
			}
		}
	}
}

// the ^brick class
function Brick(x, y, r) {
	
	var MAX_HEALTH = 100;
	var health = 100;
	var shouldRemove = false;
	
	this.draw = function(ctx) {
		ctx.beginPath();
		
		var hToF = (health / MAX_HEALTH);
		if(hToF == 0) {
			ctx.fillStyle = "rgb(0, 0, 0)";
		}
		
		if(hToF == 0.25) {
			ctx.fillStyle = "rgb(255, 120, 120)";
		}
		
		if(hToF == 0.5) {
			ctx.fillStyle = "rgb(120, 255, 120)";
		}
		
		if(hToF == 0.75) {
			ctx.fillStyle = "rgb(120, 120, 255)";
		}
		
		if(hToF == 1) {
			ctx.fillStyle = "rgb(200, 200, 200)";
		}
		
//		ctx.fillStyle = "rgb(" + (255 * ) + ", " + (150 * (health / MAX_HEALTH)) + ", 0)";
		ctx.arc(x, y, r, 0, 2*Math.PI);
		ctx.fill();
	}
	
	this.lowerHealth = function(amt) {
		health -= amt;
		if(health < 0) {
			health = 0;
			shouldRemove = true;
		}
	}
	
	this.isShouldRemove = function() {
		return shouldRemove;
	}
	
	this.getX = function(){
		return x;
	}
	
	this.getY = function(){
		return y;
	}
	
	this.getRad = function() {
		return r;
	}
	
	// ^calc item
	this.doItemDrop = function() {
		
		if(Math.random() <= 0.10)
			im.addItem(x, y, TYPE.PADDLE_SIZE_x2);
		
		else if (Math.random() <= 0.05)
			im.addItem(x, y, TYPE.MULTI_BALL_x3);
		
		else if (Math.random() <= 0.07)
			im.addItem(x, y, TYPE.MULTI_BALL_x2);
		
		else 
			console.log("No item dropped :(");
		
		score+=50;
	}
}

// ^brick manager class
function BrickManager() {
	var bricks = new Array();
	
	this.make = function(){
		var rad = 20;
		var pad = 25;
		var xoff = 10;
		var yoff = 10;
		for(var i = 0; i < CANVAS_WIDTH / (pad + (rad) * 2) - 1; i++) {
			for(var j = 0; j < CANVAS_HEIGHT / (pad + (rad) * 4.5) - 1; j++) {
				bricks.push(new Brick(xoff + rad + i * (rad * 2 + pad), yoff + rad + j * (rad * 2 + pad), rad));
			}
		}
	}
	
	this.draw = function(ctx) {
		for(var i = 0; i < bricks.length; i++) {
			if(bricks[i].isShouldRemove()) {
				bricks[i].doItemDrop();
				bricks.splice(i, 1);
				i--;
			}
			bricks[i].draw(ctx);
		}
	}
	
	this.getBricks = function() {
		return bricks;
	}
	
	this.collideWithBall = function(ball_m) {
		for(var i = 0; i < bricks.length; i++) {
			for(var j = 0; j < ball_m.getBalls().length; j++) {
				var ball = ball_m.getBalls()[j];
				var brick = bricks[i];

				var deltaX = brick.getX() - ball.getX();
				var deltaY = brick.getY() - ball.getY();
				
				var dist = Math.sqrt((deltaX * deltaX) + (deltaY * deltaY));
				
				// I have a collision
				if(dist < brick.getRad() + ball.getRad()) {
					
					// normalized surface normal of circle
					var normX = deltaX / dist;
					var normY = deltaY / dist;
					
					// normailized ball's dx and dy
					var normBallDeltaMag = Math.sqrt((ball.getDX() * ball.getDX()) + (ball.getDY() * ball.getDY()));
					var normDX = ball.getDX() / normBallDeltaMag;
					var normDY = ball.getDY() / normBallDeltaMag;
					
					// angle of refection
					var v2x = normDX - ((2 * normX)*(2 * normX))*normX;
					var v2y = normDY - ((2 * normY)*(2 * normY))*normY;
					
					var mag = Math.sqrt((v2x * v2x) + (v2y * v2y));

					// normalized refected vector
					v2x /= mag;
					v2y /= mag;
					
					brick.lowerHealth(25);
									
					// scale it up to the ball's original speed;
					v2x *= ball.getSpeed();
					v2y *= ball.getSpeed();

					ball.setDX(v2x);
					ball.setDY(v2y);
					
					// use circle parametrics to find point on circumfrance given angle
					var angle = Math.atan2(deltaY, deltaX);
					
					var circum_x = brick.getX() + (brick.getRad() + ball.getRad()) * -Math.cos(angle);
					var circum_y = brick.getY() + (brick.getRad() + ball.getRad()) * -Math.sin(angle);
					ball.setX(circum_x);
					ball.setY(circum_y);
				}
			}
		}
	}
}

// TYPES OF ITEMS ENUM
var TYPE = {
	MULTI_BALL_x3 : {value: 1, name: "Multi Ball x3", color: {r: 255, g: 13, b: 63}},
	MULTI_BALL_x2 : {value: 2, name: "Multi Ball x2", color: {r: 147, g: 12, b: 232}},
	PADDLE_SIZE_x2 : {value: 3, name: "Increased Radius x2", color: {r: 0, g: 255, b: 55}},
	SLOW_MOTION : {value: 4, name: "Slow Motion", color: {r: 230, g: 230, b: 230}}
}

function Item(x, y, type) {
	
	var name = type.name;
	var r = type.color.r;
	var g = type.color.g;
	var b = type.color.b;
	
	var rad = 16;
	
	var x = x;
	var y = y;
	
	var dx = 0;
	var dy = 1;
	
	this.shouldRemove = false;
	
	this.update = function(){
		x += dx;
		y += dy;
		
		if(y > CANVAS_HEIGHT + r) {
			shouldRemove = true;
		}
	}
	
	this.draw= function(ctx){
		ctx.fillStyle = "rgb(" + r + ", " + g + ", " + b + ")";
		ctx.beginPath();
		ctx.arc(x, y, rad, 0, 2 * Math.PI);
		ctx.fill();
	}
	
	this.useItem = function(paddle) {
		if(type === TYPE.MULTI_BALL_x2) {
			ballManager.spliteIntoMultiBallForEachBall(2);
		}
		
		if(type === TYPE.MULTI_BALL_x3) {
			ballManager.spliteIntoMultiBallForEachBall(3);
		}
		
				
		if(type === TYPE.PADDLE_SIZE_x2) {
			paddle.hasDoubleRadiusFor(5000);
		}
	}
	
	this.getX = function() {
		return x;
	}
	
	this.getY = function() {
		return y;
	}
	
	this.getRad = function() {
		return rad;
	}
}

function ItemManager() {
	var items = new Array();
	
	this.update = function() {
		for(var i = 0; i < items.length; i++) {
			items[i].update();
			
			if(items[i].shouldRemove) {
				items.splice(i, 1);
				i--;
			}
		}
	}
	
	this.draw = function(ctx) {
		for(var i = 0; i < items.length; i++) {
			items[i].draw(ctx);
		}
	}
	
	this.addItem = function(x, y, type) {
		var i = new Item(x, y, type);
		items.push(i);
	}
	
	this.collideWithPlayer = function(paddle) {
		for(var i = 0; i < items.length; i++) {
			var item = items[i];
			
			var dx = paddle.getX() - item.getX();
			var dy = paddle.getY() - item.getY();
			
			var dist = Math.sqrt((dx * dx) + (dy * dy));
			
			if(dist < paddle.getRad() + item.getRad()) {
				if(!item.shouldRemove)
					item.useItem(paddle);
				item.shouldRemove = true;
			}
		}
	}
}
}



















