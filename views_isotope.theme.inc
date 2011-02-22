<?php
// $Id:

/**
 * Preprocess function to build the isotope style plugin.
 */
function template_preprocess_views_isotope(&$vars) {
  template_preprocess_views_view_list($vars);
  
  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  
  $vars['isotope_id'] = 'views-isotope-' . $view->name . '-' . $view->style_plugin->display->id;
  
  $settings = array();
  $vars['attributes'] = array();
  $vars['sortable_fields'] = array();
  foreach ( $rows as $id => $row ) {
    foreach ( $options['sortable_fields'] as $field ) {
      if ( $field && isset($handler->rendered_fields[$id][$field]) ) {
        $vars['attributes'][$id]['data-' . $field] = $handler->rendered_fields[$id][$field];
        $vars['sortable_fields'][$field] = $fields[$field]->options['label'];
      }
    }
  }
  
  $config = array(
    'settings' => $settings,
    'sortable_fields' => $vars['sortable_fields'],
    'sort' => $options['sort'],
  );
  
  // Get stylesheets.
  drupal_add_css(drupal_get_path('module', 'views_isotope') . '/views_isotope.css');
  if ( !empty($options['skin']['css']) && is_array($options['skin']['css']) ) {
    $path = drupal_get_path('module', $options['skin']['module']);
    if ( $options['skin']['path'] ) {
      $path .= '/' . $options['skin']['path'];
    }
    
    foreach ( $options['skin']['css'] as $file ) {
      drupal_add_css($path . '/' . $file);
    }
  }
  
  drupal_add_js(libraries_get_path('jquery.isotope') . '/jquery.isotope.js');
  drupal_add_js(drupal_get_path('module', 'views_isotope') . '/views_isotope.js');
  
  drupal_add_js(array('views_isotope' => array('#' . $vars['isotope_id'] => $config)), 'setting');
}
