/**
 * Implements of Drupal.behaviors
 */
Drupal.behaviors.views_isotope = function() {
  jQuery.each(Drupal.settings.views_isotope, function(selector, config){
    var isotope = $(selector).find('ul.views-isotope-container'), sortData = {};
    
    // Create sort functions for data sorting.
    jQuery.each(config.sortable_fields, function(k, v){
      sortData[k] = function(e) {
        return parseInt(e.attr('data-' + k));
      };
    });
    
    // Append default settings.
    var settings = $.extend(config.settings, {
      animationEngine: $.browser.opera ? 'jquery' : 'best-available',
      getSortData: sortData
    });
    
    isotope.not('.views-isotope-processed').addClass('views-isotope-processed').isotope(settings);
    
    $('.views-isotope-sort li').click(function(){
      isotope.isotope({
        sortBy: $(this).attr('data-field'),
        sortAscending: config.sort
      })
    });
    
  });
};
