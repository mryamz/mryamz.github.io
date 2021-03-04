$(document).ready(function() {
	var id = "navigation-bar-wrapper";
	var ulId = "main_nav_bar";
	var navString = '<div id= + "' + id + '"><ul id= "' + ulId + '"><li><img id="csLogo" src="../../res/icon.png"></img></li><li><a href="index.html">Home</a></li><li><a href="about_me.html">About Me</a></li><li><a href="games.html">JSGames</a></li></ul></div>';
				
	$("body").prepend(navString);
	
});