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
  
  /**
   * Submit handler.
   */
  function options_submit($form, &$form_state) {
    $skins = views_isotope_get_skins();
    
    $name = $form_state['values']['style_options']['skin'];
    $form_state['values']['style_options']['skin'] = $skins[$name];
    $form_state['values']['style_options']['skin']['name'] = $name;
  }
}

/**
 * Retrieve a list of all available skins in the system.
 */
function views_isotope_get_skins($op = 'list') {
  static $skins;
  
  if ( empty($skins) ) {
    $skins = array();
    foreach ( module_implements('views_isotope_skins') as $module ) {
      $items = call_user_func($module . '_views_isotope_skins');
      if ( isset($items) && is_array($items) ) {
        foreach ( array_keys($items) as $skin ) {
          $items[$skin] += array(
            'title' => t('Untitled skin'),
            'css' => array(),
            'path' => '',
            'module' => $module,
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