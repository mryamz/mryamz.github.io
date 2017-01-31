function Particle(x, y, angleDeg, speed, exitHeight, size){
	
	
	this.x = x;
	this.y = y;
	this.exitHeight = exitHeight;
	this.angleDeg = angleDeg;
	
	angleDeg = angleDeg / 180 * Math.PI;
	
	var vx = Math.cos(angleDeg) * speed;
	var vy = Math.sin(angleDeg) * speed;
	
	var init = new Date().getTime();
	var period = Math.randomRange(3000, 5000);
	var shouldRemove = false;
	var img = new Image();
	var angle = Math.randomRange(0, 360);
	
	img.src = "images/banner/snowflake.png";
	
	img.onerror = function(){
			img.src = "../images/banner/snowflake.png";
	};
	
	this.draw = function(context){
		var elapsed = new Date().getTime() - init;
		var xOff = Math.cos(Math.PI * elapsed / period);
		
		angle++;
		
		x += vx + xOff;
		y += vy;
			
		context.save();
		context.translate(x, y);
		context.rotate(angle * Math.PI / 180);
		context.drawImage(img, -(size / 2), -(size / 2), size, size);
		context.restore();
		
		if(y > exitHeight) {
			shouldRemove = true;
		}
	}
	
	this.getShouldRemove = function() {
		return shouldRemove;
	}
};