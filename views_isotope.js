/**
 * Implements of Drupal.behaviors
 */
Drupal.behaviors.views_isotope = function() {
  jQuery.each(Drupal.settings.views_isotope, function(selector, options){
    var settings = $.extend(options, {
      animationEngine: $.browser.opera ? 'jquery' : 'best-available',
      getSortData: {
        category: function(e) {
          return e.attr('data-category');
        },
        weight: function(e) {
          return e.attr('data-weight');
        }
      }
    });
    
    $('#sort-weight').click(function(){
      $(selector).isotope({
        sortBy: 'weight',
        sortAscending: true
      });
    });
    
    $('#sort-category').click(function(){
      $(selector).isotope({
        sortBy: 'category',
        sortAscending: true
      });
    });
    
    $(selector + ':not(.views-isotope-processed)').addClass('views-isotope-processed').isotope(settings);
  });
};
