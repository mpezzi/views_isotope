$(function(){
  var isotope = $('.views-isotope-flat ul.views-isotope-container');
  
  $('div.item', isotope).click(function(){
    $(this).toggleClass('item-large');
    isotope.isotope('reLayout');
  });
});
