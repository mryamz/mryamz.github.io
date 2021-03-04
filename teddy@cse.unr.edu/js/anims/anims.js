
$(document).ready(function() {
	
	$("#beta_btn").click(function() {
		$("#element_list .element").animate({"padding-left": '175px'});
			$("#element_list").animate({"margin-left": "29%"});
			$("#element_list .element").hover(function() {
				$(this).animate({"padding-left": '360px', "margin" : "0px 70px 40px"});

			}, function() {
				$(this).animate({"padding-left": '175px', "margin" : "0px 20px 40px"});
			});
	});
	

});