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
    
    //dsm($fields);
    
  }
  
  /**
   * Submit handler.
   */
  function options_submit($form, &$form_state) {
    
  }
}
