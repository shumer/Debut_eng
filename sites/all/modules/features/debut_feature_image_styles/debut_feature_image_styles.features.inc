<?php
/**
 * @file
 * debut_feature_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function debut_feature_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: node__field_photo_listing_photo__full.
  $styles['node__field_photo_listing_photo__full'] = array(
    'name' => 'node__field_photo_listing_photo__full',
    'label' => 'node__field_photo_listing_photo__full',
    'effects' => array(
      2 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 314,
          'height' => 166,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node__field_photo_listing_photo__listing.
  $styles['node__field_photo_listing_photo__listing'] = array(
    'name' => 'node__field_photo_listing_photo__listing',
    'label' => 'node__field_photo_listing_photo__listing',
    'effects' => array(
      3 => array(
        'label' => 'Масштабирование и обрезка',
        'help' => '«Масштабирование и обрезка» сначала масштабирует изображение, а затем обрезает большее значение. Это наиболее эффективный способ создания миниатюр без искажения пропорций исходного изображения.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 314,
          'height' => 166,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
