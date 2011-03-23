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
    
    // Append default settings and sorting data.
    var settings = $.extend(config.settings, {
      animationEngine: $.browser.opera ? 'jquery' : 'best-available',
      getSortData: sortData
    });
    
    isotope.not('.views-isotope-processed').addClass('views-isotope-processed').isotope(settings);
    
    $('.views-isotope-sort li', selector).click(function(){
      if ( $(this).attr('data-field') != '' ) {
        $('.views-isotope-sort li', selector).removeClass('active');
        $(this).addClass('active');
        
        isotope.isotope({
          sortBy: $(this).attr('data-field'),
          sortAscending: ( $(this).data('sort') == 'asc' )
        });
      }
    });
    
    $('.views-isotope-filter ul li', selector).click(function(){
      if ( $(this).attr('data-filter') != '' ) {
        $('.views-isotope-filter li', selector).removeClass('active');
        $(this).addClass('active');
        
        isotope.isotope({
          filter: $(this).attr('data-filter')
        });
      }
    });
    
  });
};
