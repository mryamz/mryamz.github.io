var particles = new Array(0);

var particleManager = {	
	
	height: 0,
	sizeofParticle: 32,
	
	init: function(pSize, height){
		this.height = height;
		
		for(var i = 0; i < pSize; i++) {
			this.addInit();
		}
	},
		
	draw: function(context){
		for(var i = 0; i < particles.length; i++) {
			particles[i].draw(context);
			if(particles[i].getShouldRemove()) {
				particles.splice(i, 1);
				i--;
				this.add();
			}
		}		
	},
	
	add: function() {
		var angle = 45 + Math.randomRange(-15, 15);
		var side1 = this.height;
		var x = Math.tan(angle) * side1;
		particles.push(new Particle(Math.randomRange(-x, Math.max(document.documentElement.clientWidth),
															 window.innerWidth || 0), -this.sizeofParticle, 45, Math.randomRange(1, 2.5), this.height + this.sizeofParticle / 2, Math.randomRange(16, 32)));
	},
	
	addInit: function() {
		particles.push(new Particle(Math.random() * Math.max(document.documentElement.clientWidth,
															 window.innerWidth || 0), Math.randomRange(-this.sizeofParticle, this.height), 45, Math.randomRange(1, 2.5), this.height + this.sizeofParticle / 2, Math.randomRange(16, 32)));
	}
};