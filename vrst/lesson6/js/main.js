$(function () {

	document.getElementById('btn').onclick = function (e) {
		e.preventDefault();
		alert("Многое!");
	}

	$(window).scroll(function() {
	   $('.goals').each(function(){
			var imagePos = $(this).offset().top;
			var topOfWindow = $(window).scrollTop();
			if (imagePos < topOfWindow+650) {
				$(this).addClass("fadeInUp");
			}
		});
	});

	$(window).scroll(function() {
	    $('.section_title').each(function(){
	        var imagePos = $(this).offset().top;
	        var topOfWindow = $(window).scrollTop();
	        if (imagePos < topOfWindow+650) {
	            $(this).addClass("fadeInDown");
	        }
	    });
	});

	$(window).scroll(function() {
	    $('.container').each(function(){
	        var imagePos = $(this).offset().top;
	        var topOfWindow = $(window).scrollTop();
	        if (imagePos < topOfWindow+650) {
	            $(this).addClass("fadeInUp");
	        }
	    });
	});
})