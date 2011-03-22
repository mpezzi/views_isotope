<div class="views-isotope <?php print $skin_class; ?>" id="<?php print $isotope_id; ?>">
  <?php if ( count($sortable_fields) ): ?>
    <ul class="views-isotope-sort">
    <?php foreach ( $sortable_fields as $field => $label ): ?>
      <li id="sort-<?php print $name; ?>" <?php if ( isset($field['attributes']) ) print drupal_attributes($field['attributes']); ?>><?php print t('Sort by %label', array('%label' => $field['label'])); ?></li>
    <?php endforeach; ?>
    </ul>
  <?php endif; ?>
  
  <?php if ( count($filterable_fields) ): ?>
    <ul class="views-isotope-filter">
    <?php foreach ( $filterable_fields as $field => $label ): ?>
      <li id="sort-<?php print $field; ?>" data-field="<?php print $field; ?>"><?php print t('Filter by %label', array('%label' => $label)); ?></li>
    <?php endforeach; ?>
    </ul>
  <?php endif; ?>
  
  <<?php print $options['type']; ?> class="views-isotope-container">
    <?php foreach ( $rows as $id => $row ): ?>
      <li class="<?php print $classes[$id]; ?>" <?php if ( isset($attributes[$id]) ) print drupal_attributes($attributes[$id]); ?>>
        <div class="item"><?php print $row; ?></div>
      </li>
    <?php endforeach; ?>
  <<?php print $options['type']; ?>>
</div>
