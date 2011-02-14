/**
 * Implements of Drupal.behaviors
 */
Drupal.behaviors.views_isotope = function() {
  jQuery.each(Drupal.settings.views_isotope, function(selector, options){
    $(selector + ':not(.views-isotope-processed)').addClass('views-isotope-processed').isotope(options);
  });
};
