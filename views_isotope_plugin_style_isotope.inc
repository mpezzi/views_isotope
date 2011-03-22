<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class views_isotope_plugin_style_isotope extends views_plugin_style_list {
  
  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    
    $options['sortable_fields'] = array('default' => array());
    $options['sortable_fields_order'] = array('default' => array());
    $options['filterable_fields'] = array('default' => array());
    $options['sort'] = array('default' => 0);
    
    return $options;
  }
  
  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    // Build a list of all fields.
    $fields = array();
    foreach ( $this->display->handler->get_handlers('field') as $field => $handler ) {
      if ( $label = $handler->label() ) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }
    
    $form['sortable_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Sortable Fields'),
      '#description' => t('Fields that are sortable via Isotope'),
      '#options' => $fields,
      '#default_value' => $this->options['sortable_fields'],
    );
    
    $form['sortable_fields_order'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Sortable Fields Reverse Order'),
      '#description' => t('Field sort order'),
      '#options' => $fields,
      '#default_value' => $this->options['sortable_fields_order'],
    );
    
    $form['filterable_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Filterable Fields'),
      '#description' => t('Fields that are filterable via Isotope'),
      '#options' => $fields,
      '#default_value' => $this->options['filterable_fields'],
    );
    
    $form['sort'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ascending'),
      '#description' => t('Sort fields ascending or descending.'),
      '#default_value' => $this->options['sort'],
    );
    
    $form['skin'] = array(
      '#type' => 'select',
      '#title' => t('Skin'),
      '#description' => t('Select the skin to use for this display.'),
      '#options' => views_isotope_get_skins('info'),
      '#default_value' => $this->options['skin'],
    );
    
  }
}

/**
 * Retrieve a list of all available skins in the system.
 */
function views_isotope_get_skins($op = 'list') {
  global $theme_key;
  static $skins;
  
  $hook = 'views_isotope_skins';
  $hooks = module_implements($hook);
  
  // Collect theme hooks.
  $themes = list_themes();
  if ( isset($themes[$theme_key]->base_themes) ) {
    $theme_keys = array_keys($themes[$theme_key]->base_themes);
    $theme_keys[] = $theme_keys;
  }
  else {
    $theme_keys = array(variable_get('theme_default', 'none'));
  }
  
  // Filter out theme hooks that don't exist.
  foreach ( $theme_keys as $key => $theme ) {
    $template_file = drupal_get_path('theme', $theme) . '/template.php';
    
    if ( file_exists($template_file) ) {
      include_once $template_file;
      
      if ( !function_exists($theme . '_' . $hook) ) {
        unset($theme_keys[$key]);
      }
    }
    
    if ( is_array($theme) ) {
      unset($theme_keys[$key]);
    }
  }
  
  if ( count($theme_keys) > 0 ) {
    $hooks = array_merge($hooks, $theme_keys);
  }
  
  if ( empty($skins) ) {
    $skins = array();
    foreach ( $hooks as $implementation ) {
      $items = call_user_func($implementation . '_views_isotope_skins');
      if ( isset($items) && is_array($items) ) {
        foreach ( array_keys($items) as $skin ) {
          $items[$skin] += array(
            'title' => t('Untitled skin'),
            'css' => array(),
            'js' => array(),
            'settings' => array(),
            'path' => '',
            'implementation' => $implementation,
            'type' => isset($themes[$implementation]) ? 'theme' : 'module',
          );
        }
        $skins = array_merge($skins, $items);
      }
    }
  }
  
  if ( $op == 'info' ) {
    $skin_info = array();
    foreach ( $skins as $name => $skin ) {
      $skin_info[$name] = $skin['title'];
    }
    
    asort($skin_info);
    
    return $skin_info;
  }
  
  return $skins;
}