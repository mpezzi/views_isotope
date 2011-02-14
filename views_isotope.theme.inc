<?php
// $Id:

/**
 * Preprocess function to build the isotope style plugin.
 */
function template_preprocess_views_isotope(&$vars) {
  //template_preprocess_views_view_list($vars);
  
  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  
  drupal_add_js(libraries_get_path('jquery.isotope') . '/jquery.isotope.min.js');
  drupal_add_js(drupal_get_path('module', 'views_isotope') . '/views_isotope.js');
  
  
}