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
    
    // Options
    
    return $options;
  }
  
  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
  }
  
  /**
   * Submit handler.
   */
  function options_submit($form, &$form_state) {
    
  }
}
