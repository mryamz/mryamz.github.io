var Banner = {
	
	canvas: null,
	context: null,
	init: null,
	period: null,

		
	init: function(){ 
		this.canvas = document.getElementById('canvas_banner');
		this.context = canvas.getContext('2d');		
		this.init = new Date().getTime();
		this.period = 6000;
		
		setInterval(Banner.loop, 1000/30);		
		particleManager.init(500, canvas.height);
	},
	
	loop: function(){
		var w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0) * 1;
		canvas.width = w;
		context.clearRect(0, 0, canvas.width, canvas.height);
		context.beginPath();

		context.fillStyle = "#F2F2F2";
		context.fillRect(0, 0, canvas.width, canvas.height);
		
		var elapsed = (new Date().getTime() - init);
		var a = Math.abs(Math.sin(Math.PI * elapsed / period)) / 3;
		
		context.fillStyle = "rgba(0, 0, 0, " + a +")";
		context.font = "75px Arial";
		var string = "mryamz ";
		var length = context.measureText(string).width;
		context.fillText(string, w / 2 - length / 2, 100);
		
				
		// draw particles
		particleManager.draw(context);

		context.closePath();		
	}
};

window.addEventListener("load", Banner.init, false);