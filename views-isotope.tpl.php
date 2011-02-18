<?php
// $Id:



?>

<?php if ( count($sortable_fields) ): ?>
  <ul class="views-isotope-sort" style="padding-top: 100px">
  <?php foreach ( $sortable_fields as $field => $label ): ?>
    <li id="sort-<?php print $field; ?>" data-field="<?php print $field; ?>"><?php print t('Sort by %label', array('%label' => $label)); ?></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>

<div class="views-isotope">
  <<?php print $options['type']; ?> class="views-isotope-container" id="<?php print $isotope_id; ?>">
    <?php foreach ( $rows as $id => $row ): ?>
      <li class="<?php print $classes[$id]; ?>" <?php if ( isset($attributes[$id]) ) print drupal_attributes($attributes[$id]); ?>>
        <div class="item"><?php print $row; ?></div>
      </li>
    <?php endforeach; ?>
  <<?php print $options['type']; ?>>
</div>
