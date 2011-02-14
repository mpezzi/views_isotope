<?php
// $Id:

?>

<ul style="padding-top: 100px">
  <li id="sort-weight">Sort by Weight</li>
  <li id="sort-category">Sort by Category</li>
</ul>

<div class="views-isotope">
  <<?php print $options['type']; ?> class="views-isotope-container" id="<?php print $isotope_id; ?>">
    <?php foreach ( $rows as $id => $row ): ?>
      <li class="<?php print $classes[$id]; ?>" <?php print drupal_attributes($attributes[$id]); ?>>
        <div class="item"><?php print $row; ?></div>
      </li>
    <?php endforeach; ?>
  <<?php print $options['type']; ?>>
</div>
